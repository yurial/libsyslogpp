/*
libsyslogpp - c++ wrapper for standard syslog interface
copyright (c) 2013  yuri diachenko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

