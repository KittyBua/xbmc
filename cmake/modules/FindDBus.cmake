#.rst:
# FindDBUS
# -------
# Finds the DBUS library
#
# This will define the following target:
#
#   ${APP_NAME_LC}::DBus   - The DBUS library

if(NOT TARGET ${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAME})
  find_package(PkgConfig ${SEARCH_QUIET})
  if(PKG_CONFIG_FOUND)
    pkg_check_modules(PC_DBUS dbus-1 ${SEARCH_QUIET})
  endif()

  find_path(DBUS_INCLUDE_DIR NAMES dbus/dbus.h
                             PATH_SUFFIXES dbus-1.0
                             HINTS ${PC_DBUS_INCLUDE_DIR})
  find_path(DBUS_ARCH_INCLUDE_DIR NAMES dbus/dbus-arch-deps.h
                                  PATH_SUFFIXES dbus-1.0/include
                                  HINTS ${PC_DBUS_LIBDIR}
                                  PATHS /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE})
  find_library(DBUS_LIBRARY NAMES dbus-1
                            HINTS ${PC_DBUS_LIBDIR})

  set(DBUS_VERSION ${PC_DBUS_VERSION})

  if(NOT VERBOSE_FIND)
     set(${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY TRUE)
   endif()

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(DBus
                                    REQUIRED_VARS DBUS_LIBRARY DBUS_INCLUDE_DIR DBUS_ARCH_INCLUDE_DIR
                                    VERSION_VAR DBUS_VERSION)

  if(DBUS_FOUND)
    add_library(${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAME} UNKNOWN IMPORTED)
    set_target_properties(${APP_NAME_LC}::${CMAKE_FIND_PACKAGE_NAME} PROPERTIES
                                                                     IMPORTED_LOCATION "${DBUS_LIBRARY}"
                                                                     INTERFACE_INCLUDE_DIRECTORIES "${DBUS_INCLUDE_DIR};${DBUS_ARCH_INCLUDE_DIR}"
                                                                     INTERFACE_COMPILE_DEFINITIONS HAS_DBUS)
  endif()
endif()
