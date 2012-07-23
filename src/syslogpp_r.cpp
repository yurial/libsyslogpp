#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#include <pthread.h>
#include "syslogpp.h"

pthread_once_t syslog_once = PTHREAD_ONCE_INIT;
pthread_key_t  syslog_key;

void syslog_cleanup(void* p)
{
syslog_t* log = (syslog_t*)p;
delete log;
}

void syslog_init() throw(std::bad_alloc)
{
int ret = 0;
ret = pthread_key_create( &syslog_key, syslog_cleanup );
if ( 0 != ret )
    {
    throw std::bad_alloc();
    }
}

syslog_t& syslog_get() throw(std::bad_alloc,std::runtime_error)
{
int ret = pthread_once( &syslog_once, syslog_init );
if ( 0 != ret )
    {
    throw std::runtime_error( "libsyslogpp_r: internal error (syslog_init)" );
    }
syslog_t* log = (syslog_t*)pthread_getspecific( syslog_key );
if ( NULL == log )
    {
    log = new syslog_t;
    ret = pthread_setspecific( syslog_key, log );
    if ( 0 != ret )
        {
        delete log;
        throw std::bad_alloc();
        }
    }
return *log;
}

