#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3DUtils" for configuration "Debug"
set_property(TARGET Qt6::Quick3DUtils APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::Quick3DUtils PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/Qt6Quick3DUtilsd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Qt6Quick3DUtilsd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Quick3DUtils )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Quick3DUtils "${_IMPORT_PREFIX}/lib/Qt6Quick3DUtilsd.lib" "${_IMPORT_PREFIX}/bin/Qt6Quick3DUtilsd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
