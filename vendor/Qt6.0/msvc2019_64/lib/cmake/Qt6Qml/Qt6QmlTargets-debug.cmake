#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Qml" for configuration "Debug"
set_property(TARGET Qt6::Qml APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::Qml PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/Qt6Qmld.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/Qt6Qmld.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Qml )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Qml "${_IMPORT_PREFIX}/lib/Qt6Qmld.lib" "${_IMPORT_PREFIX}/bin/Qt6Qmld.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
