#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QuickShapes" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::QuickShapes APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::QuickShapes PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/Qt6QuickShapes.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Qt6QuickShapes.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QuickShapes )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QuickShapes "${_IMPORT_PREFIX}/lib/Qt6QuickShapes.lib" "${_IMPORT_PREFIX}/bin/Qt6QuickShapes.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
