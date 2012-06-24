#ifndef SYSLOGPP_H
#define SYSLOGPP_H

#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#ifdef HAVE_SYSLOG
    #include <syslog.h>
#endif

#include <stdarg.h>
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
inline                  syslog_t(int prio = LOG_WARNING);
inline                  ~syslog_t();

//change priority operator
inline  std::ostream&   operator () (int prio);

//standart interface
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
}

void syslog_t::operator () (int prio, const char* fmt, ...) const
{
va_list args;
va_start( args, fmt );
vsyslog( prio, fmt, args );
va_end( args );
}

#ifndef HAVE_PTHREAD
    extern syslog_t g_syslog;
    #define syslog g_syslog
#else
    syslog_t& syslog_get();
    #define syslog syslog_get()
#endif

#endif

