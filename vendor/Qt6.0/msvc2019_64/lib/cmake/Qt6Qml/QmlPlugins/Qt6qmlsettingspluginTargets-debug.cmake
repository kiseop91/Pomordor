#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::qmlsettingsplugin" for configuration "Debug"
set_property(TARGET Qt6::qmlsettingsplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::qmlsettingsplugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./qml/Qt/labs/settings/qmlsettingsplugind.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::qmlsettingsplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::qmlsettingsplugin "${_IMPORT_PREFIX}/./qml/Qt/labs/settings/qmlsettingsplugind.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
