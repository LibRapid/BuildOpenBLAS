#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "OpenBLAS64::OpenBLAS" for configuration "Release"
set_property(TARGET OpenBLAS64::OpenBLAS APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OpenBLAS64::OpenBLAS PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "m"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopenblas_64.so.0.3"
  IMPORTED_SONAME_RELEASE "libopenblas_64.so.0"
  )

list(APPEND _cmake_import_check_targets OpenBLAS64::OpenBLAS )
list(APPEND _cmake_import_check_files_for_OpenBLAS64::OpenBLAS "${_IMPORT_PREFIX}/lib/libopenblas_64.so.0.3" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
