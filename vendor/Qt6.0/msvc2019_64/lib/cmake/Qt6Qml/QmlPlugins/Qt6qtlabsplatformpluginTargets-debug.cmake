#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::qtlabsplatformplugin" for configuration "Debug"
set_property(TARGET Qt6::qtlabsplatformplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::qtlabsplatformplugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./qml/Qt/labs/platform/qtlabsplatformplugind.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::qtlabsplatformplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::qtlabsplatformplugin "${_IMPORT_PREFIX}/./qml/Qt/labs/platform/qtlabsplatformplugind.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
