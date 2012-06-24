#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif
#include "syslogpp.h"

syslog_t g_syslog;

#ifdef HAVE_PTHREAD
#include <pthread.h>
pthread_once_t syslog_once = PTHREAD_ONCE_INIT;
pthread_key_t  syslog_key;

void syslog_init();
void syslog_cleanup(void* p);
syslog_t& syslog_get();

void syslog_init()
{
int ret = pthread_key_create( &syslog_key, syslog_cleanup );
syslog_t* log = new syslog_t;
pthread_setspecific( syslog_key, log );
}

void syslog_cleanup(void* p)
{
syslog_t* log = (syslog_t*)p;
delete log;
}

syslog_t& syslog_get()
{
int ret = pthread_once( &syslog_once, syslog_init );
syslog_t* log = (syslog_t*)pthread_getspecific( syslog_key );
return *log;
}
#endif

