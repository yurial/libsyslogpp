#include <stdlib.h>
#include <iostream>
#include <syslogpp.h>

int main(int argc, char* argv[])
{
syslog.open( NULL, LOG_PID, LOG_USER );
syslog( LOG_DEBUG );
std::cerr << std::nounitbuf; //Do not force flushes after insertions
std::cerr.rdbuf( syslog.rdbuf() );
std::cerr << "std::cerr stream interface" << std::endl;
syslog.close();
return EXIT_SUCCESS;
}

