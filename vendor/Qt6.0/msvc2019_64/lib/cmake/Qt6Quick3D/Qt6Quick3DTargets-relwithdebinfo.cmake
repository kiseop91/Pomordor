#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3D" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::Quick3D APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::Quick3D PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/Qt6Quick3D.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Qt6Quick3D.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Quick3D )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Quick3D "${_IMPORT_PREFIX}/lib/Qt6Quick3D.lib" "${_IMPORT_PREFIX}/bin/Qt6Quick3D.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
