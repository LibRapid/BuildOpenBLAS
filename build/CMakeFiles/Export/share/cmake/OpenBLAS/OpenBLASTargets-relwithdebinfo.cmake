#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "OpenBLAS::OpenBLAS" for configuration "RelWithDebInfo"
set_property(TARGET OpenBLAS::OpenBLAS APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(OpenBLAS::OpenBLAS PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/openblas.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/openblas.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OpenBLAS::OpenBLAS )
list(APPEND _IMPORT_CHECK_FILES_FOR_OpenBLAS::OpenBLAS "${_IMPORT_PREFIX}/lib/openblas.lib" "${_IMPORT_PREFIX}/bin/openblas.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
