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
#include <syslogpp.h>

int main(int argc, char* argv[])
{
openlog( NULL, LOG_PID, LOG_USER );
syslog( LOG_DEBUG, "%s", "standard interface" );
closelog();
return EXIT_SUCCESS;
}

