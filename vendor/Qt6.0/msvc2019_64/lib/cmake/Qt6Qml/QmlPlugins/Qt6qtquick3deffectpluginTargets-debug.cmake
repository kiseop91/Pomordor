#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::qtquick3deffectplugin" for configuration "Debug"
set_property(TARGET Qt6::qtquick3deffectplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::qtquick3deffectplugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./qml/QtQuick3D/Effects/qtquick3deffectplugind.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::qtquick3deffectplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::qtquick3deffectplugin "${_IMPORT_PREFIX}/./qml/QtQuick3D/Effects/qtquick3deffectplugind.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
