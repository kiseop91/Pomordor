#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QuickControls2" for configuration "Debug"
set_property(TARGET Qt6::QuickControls2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::QuickControls2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/Qt6QuickControls2d.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Qt6QuickControls2d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QuickControls2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QuickControls2 "${_IMPORT_PREFIX}/lib/Qt6QuickControls2d.lib" "${_IMPORT_PREFIX}/bin/Qt6QuickControls2d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
