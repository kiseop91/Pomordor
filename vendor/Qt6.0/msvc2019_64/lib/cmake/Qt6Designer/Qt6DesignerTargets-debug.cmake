#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Designer" for configuration "Debug"
set_property(TARGET Qt6::Designer APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::Designer PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/Qt6Designerd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Qt6Designerd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Designer )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Designer "${_IMPORT_PREFIX}/lib/Qt6Designerd.lib" "${_IMPORT_PREFIX}/bin/Qt6Designerd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
