#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QmlDebug" for configuration "Debug"
set_property(TARGET Qt6::QmlDebug APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::QmlDebug PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/Qt6QmlDebugd.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QmlDebug )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QmlDebug "${_IMPORT_PREFIX}/lib/Qt6QmlDebugd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
