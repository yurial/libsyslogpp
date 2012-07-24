#include <stdlib.h>
#include <syslogpp.h>

int main()
{
syslog.open( NULL, LOG_PID, LOG_USER );
for (int i = 0; i < 1024*1024*1024; ++i)
    {
    syslog( LOG_DEBUG ) << "syslog stream interface " << i << std::endl;
    }
syslog.close();
pause();
return EXIT_SUCCESS;
}

