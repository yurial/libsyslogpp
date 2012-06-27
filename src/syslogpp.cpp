#include "syslogpp.h"

syslog_t g_syslog;

syslog_t& syslog_get() throw(std::bad_alloc,std::runtime_error)
{
return g_syslog;
}

