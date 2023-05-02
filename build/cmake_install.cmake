# Install script for directory: C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/OpenBLAS")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/DEBUG/openblas.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/RELEASE/openblas.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/MINSIZEREL/openblas.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/RELWITHDEBINFO/openblas.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/DEBUG/openblas.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/RELEASE/openblas.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/MINSIZEREL/openblas.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lib/RELWITHDEBINFO/openblas.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openblas" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/openblas_config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openblas" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/generated/cblas.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openblas" TYPE FILE FILES
    "C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS/lapack-netlib/LAPACKE/example/lapacke_example_aux.h"
    "C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS/lapack-netlib/LAPACKE/include/lapack.h"
    "C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS/lapack-netlib/LAPACKE/include/lapacke.h"
    "C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS/lapack-netlib/LAPACKE/include/lapacke_config.h"
    "C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS/lapack-netlib/LAPACKE/include/lapacke_mangling.h"
    "C:/dev/librapid_dev/BuildOpenBLAS/OpenBLAS/lapack-netlib/LAPACKE/include/lapacke_utils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openblas/openblas" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/lapacke_mangling.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/openblas.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/OpenBLASConfig.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE RENAME "OpenBLASConfigVersion.cmake" FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/OpenBLASConfigVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS/OpenBLASTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS/OpenBLASTargets.cmake"
         "C:/dev/librapid_dev/BuildOpenBLAS/build/CMakeFiles/Export/share/cmake/OpenBLAS/OpenBLASTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS/OpenBLASTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS/OpenBLASTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/CMakeFiles/Export/share/cmake/OpenBLAS/OpenBLASTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/CMakeFiles/Export/share/cmake/OpenBLAS/OpenBLASTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/CMakeFiles/Export/share/cmake/OpenBLAS/OpenBLASTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/CMakeFiles/Export/share/cmake/OpenBLAS/OpenBLASTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenBLAS" TYPE FILE FILES "C:/dev/librapid_dev/BuildOpenBLAS/build/CMakeFiles/Export/share/cmake/OpenBLAS/OpenBLASTargets-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/interface/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/driver/level2/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/driver/level3/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/driver/others/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/lapack/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/kernel/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/utest/cmake_install.cmake")
  include("C:/dev/librapid_dev/BuildOpenBLAS/build/ctest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/dev/librapid_dev/BuildOpenBLAS/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
