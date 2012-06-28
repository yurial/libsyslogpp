#ifndef SYSLOGPP_H
#define SYSLOGPP_H

#ifdef HAVE_SYSLOG_H
    #include <syslog.h>
    #ifndef SYSLOGPP_DEFAULT_PRIO
        #define SYSLOGPP_DEFAULT_PRIO LOG_ALERT
    #endif
#else
    #include <stdarg.h>
    #ifndef SYSLOGPP_DEFAULT_PRIO
        #define SYSLOGPP_DEFAULT_PRIO 0
    #endif
    extern "C"
        {
        void openlog(const char *ident, int option, int facility);
        void syslog(int priority, const char *format, ...);
        void closelog(void);
        void vsyslog(int priority, const char *format, va_list ap);
        int  setlogmask(int mask);
        }
#endif

#include <stdarg.h>
#include <stdexcept>
#include <sstream>

class syslogbuf:
    public std::stringbuf
{
protected:
                int     m_prio;

inline                  syslogbuf(int prio);
inline          void    setprio(int prio);
inline          int     sync();
};

class syslog_t:
    protected syslogbuf,
    public std::ostream
{
public:
inline                  syslog_t(int prio = SYSLOGPP_DEFAULT_PRIO);
inline                  ~syslog_t();

//operator of priority modification
inline  std::ostream&   operator () (int prio);

//standard interface
inline  void            open(const char* procname, int option, int facility);
inline  void            close();
inline  int             setmask(int mask);
inline  void            operator () (int prio, const char* fmt, ...) const;
};

syslogbuf::syslogbuf(int prio):
    m_prio( prio )
{
}

void syslogbuf::setprio(int prio)
{
pubsync();
m_prio = prio;
}

int syslogbuf::sync()
{
char* str = pbase();
if ( epptr() != str )
    {
    sputc( '\0' );
    syslog( m_prio, "%s", str );
    setp( str, str );
    }
return 0; //success
}

syslog_t::syslog_t(int prio):
    syslogbuf( prio ), std::ostream( static_cast<std::streambuf*>( this ) )
{
}

syslog_t::~syslog_t()
{
pubsync();
}

void syslog_t::open(const char* procname, int option, int facility)
{
openlog( procname, option, facility );
}

void syslog_t::close()
{
closelog();
}

int syslog_t::setmask(int mask)
{
return setlogmask( mask );
}

std::ostream& syslog_t::operator () (const int prio)
{
setprio( prio );
return *this;
}

void syslog_t::operator () (int prio, const char* fmt, ...) const
{
va_list args;
va_start( args, fmt );
vsyslog( prio, fmt, args );
va_end( args );
}

syslog_t& syslog_get() throw(std::bad_alloc,std::runtime_error);
#define syslog syslog_get()

#endif

