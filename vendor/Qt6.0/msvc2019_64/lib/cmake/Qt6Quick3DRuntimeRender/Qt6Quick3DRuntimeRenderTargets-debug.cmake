#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3DRuntimeRender" for configuration "Debug"
set_property(TARGET Qt6::Quick3DRuntimeRender APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::Quick3DRuntimeRender PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/Qt6Quick3DRuntimeRenderd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Qt6Quick3DRuntimeRenderd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Quick3DRuntimeRender )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Quick3DRuntimeRender "${_IMPORT_PREFIX}/lib/Qt6Quick3DRuntimeRenderd.lib" "${_IMPORT_PREFIX}/bin/Qt6Quick3DRuntimeRenderd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
