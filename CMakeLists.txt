cmake_minimum_required(VERSION 2.6)
project(libsyslogpp)

find_package(Threads REQUIRED)

include(CheckIncludeFileCXX)
CHECK_INCLUDE_FILE_CXX("${header}" HAVE_CONFIG_H)
if (HAVE_CONFIG_H)
    add_definitions(-DHAVE_CONFIG_H)
endif()

include_directories(src/)
add_library(syslogpp src/syslogpp.cpp)
add_library(syslogpp_r src/syslogpp_r.cpp)

set_target_properties(syslogpp syslogpp_r PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

install(TARGETS syslogpp syslogpp_r DESTINATION lib)
install(FILES src/syslogpp.h DESTINATION include)
install(FILES man/libsyslogpp.7 DESTINATION share/man/man7/)
install(FILES COPYING DESTINATION share/doc/libsyslogpp RENAME copyright)
install(FILES ChangeLog NEWS README AUTHORS DESTINATION share/doc/libsyslogpp)

set (CPACK_GENERATOR "DEB;RPM")
set (CPACK_DEBIAN_PACKAGE_MAINTAINER "Yuri Dyachenko <admin@yurial.ru>")
set (CPACK_PACKAGE_VERSION_MAJOR "0")
set (CPACK_PACKAGE_VERSION_MINOR "7")
set (CPACK_PACKAGE_VERSION_PATCH "0")

include(CPack)
