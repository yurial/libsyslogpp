#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#include <stdlib.h>
#include <syslogpp.h>

int main()
{
syslog.open( NULL, LOG_PID, LOG_DAEMON );
syslog( LOG_NOTICE, "%s", "test1" );
syslog( LOG_NOTICE ) << "test2" << std::endl;
syslog.close();
return EXIT_SUCCESS;
}

