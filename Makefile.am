ACLOCAL_AMFLAGS = -I m4
lib_LIBRARIES = @BUILD_LIBS@
EXTRA_LIBRARIES = libsyslogpp.a libsyslogpp_r.a
libsyslogpp_a_SOURCES = src/syslogpp.cpp
libsyslogpp_r_a_SOURCES = src/syslogpp_r.cpp
library_includedir=$(includedir)/
library_include_HEADERS = src/syslogpp.h
man_MANS = man/libsyslogpp.7
EXTRA_DIST = ebuild $(man_MANS) src/example.cpp

