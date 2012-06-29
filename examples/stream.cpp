#include <stdlib.h>
#include <syslogpp.h>

int main()
{
syslog.open( NULL, LOG_PID, LOG_USER );
syslog( LOG_DEBUG ) << "syslog stream interface" << std::endl;
syslog.close();
return EXIT_SUCCESS;
}

