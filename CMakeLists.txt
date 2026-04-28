cmake_minimum_required(VERSION 3.31)
project(running-with-scissors VERSION 0.0 LANGUAGES C)

include(GNUInstallDirs)

cmake_pkg_config(IMPORT libcap REQUIRED)

add_executable(
  rws
  rws.c
  caps.c
  rws.h)

target_link_libraries(rws
  PRIVATE
  PkgConfig::libcap)


install(TARGETS rws DESTINATION bin)
install(FILES rws.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
