#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Quick3DAssetImport" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::Quick3DAssetImport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::Quick3DAssetImport PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/Qt6Quick3DAssetImport.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Qt6Quick3DAssetImport.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Quick3DAssetImport )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Quick3DAssetImport "${_IMPORT_PREFIX}/lib/Qt6Quick3DAssetImport.lib" "${_IMPORT_PREFIX}/bin/Qt6Quick3DAssetImport.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
