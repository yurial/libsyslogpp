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

