#include <stdlib.h>
#include <iostream>
#include <syslogpp.h>

int main(int argc, char* argv[])
{
syslog.open( NULL, LOG_PID, LOG_USER );
syslog( LOG_ERR );
std::clog.rdbuf( syslog.rdbuf() );
std::clog << "std::clog stream interface" << std::endl;
syslog.close();
return EXIT_SUCCESS;
}

