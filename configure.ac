AC_INIT([syslogpp],[0.2])
AM_INIT_AUTOMAKE([syslogpp],[0.2])
AC_CONFIG_MACRO_DIR([m4])
m4_include([m4/acx_pthread.m4])
: ${CXXFLAGS="-O3 -Wall"}
AC_C_INLINE
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_CHECK_HEADER( [syslog.h], [AC_DEFINE(HAVE_SYSLOG,1,[Define if you have syslog.h header file.])] )
AC_ARG_ENABLE([debug],AS_HELP_STRING(--enable-debug,enable debug), export CXXFLAGS="-O0 -g")
AC_ARG_ENABLE([pthread],AS_HELP_STRING(--enable-pthread,enable pthread support), 
    [ACX_PTHREAD( [AC_DEFINE(HAVE_PTHREAD,1,[Define if you have POSIX threads libraries and header files.])],[pthread not supported, configure program with --disable-pthread])]
    )

LIBS="$PTHREAD_LIBS $LIBS"
CXXFLAGS="$CXXFLAGS $PTHREAD_CFLAGS"

AC_CONFIG_HEADERS(src/config.h)
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

