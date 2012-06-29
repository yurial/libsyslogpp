#include <stdlib.h>
#include <syslogpp.h>

int main(int argc, char* argv[])
{
openlog( NULL, LOG_PID, LOG_USER );
syslog( LOG_DEBUG, "%s", "standard interface" );
closelog();
return EXIT_SUCCESS;
}

