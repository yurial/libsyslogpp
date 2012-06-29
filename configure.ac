AC_INIT([syslogpp],[0.4])
AM_INIT_AUTOMAKE([syslogpp],[0.4])
AC_CONFIG_MACRO_DIR([m4])
m4_include([m4/acx_pthread.m4])
: ${CXXFLAGS=""}
AC_C_INLINE
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_CHECK_HEADER( [syslog.h], [AC_DEFINE(HAVE_SYSLOG_H,1,[Define if you have syslog.h header file.])] )
ACX_PTHREAD([export BUILD_LIBS="libsyslogpp.a libsyslogpp_r.a"],[export BUILD_LIBS="libsyslogpp.a"])

AC_ARG_ENABLE([debug],[AS_HELP_STRING(--enable-debug,enable debug)])
if [ test "_$enable_debug" = "_yes" ]; then
    CXXFLAGS="-O0 -g ${CXXFLAGS}"
    fi

AC_SUBST([BUILD_LIBS])
AC_CONFIG_HEADERS(src/config.h)
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

