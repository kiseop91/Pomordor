#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick" for configuration "Debug"
set_property(TARGET Qt6::Quick APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::Quick PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/Qt6Quickd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Qt6Quickd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Quick )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Quick "${_IMPORT_PREFIX}/lib/Qt6Quickd.lib" "${_IMPORT_PREFIX}/bin/Qt6Quickd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
