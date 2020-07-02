
add_library(Qt5::DefaultGeometryLoaderPlugin MODULE IMPORTED)


_populate_3DRender_plugin_properties(DefaultGeometryLoaderPlugin RELEASE "geometryloaders/defaultgeometryloader.dll" TRUE)
_populate_3DRender_plugin_properties(DefaultGeometryLoaderPlugin DEBUG "geometryloaders/defaultgeometryloaderd.dll" TRUE)

list(APPEND Qt53DRender_PLUGINS Qt5::DefaultGeometryLoaderPlugin)
set_property(TARGET Qt5::3DRender APPEND PROPERTY QT_ALL_PLUGINS_geometryloaders Qt5::DefaultGeometryLoaderPlugin)
set_property(TARGET Qt5::DefaultGeometryLoaderPlugin PROPERTY QT_PLUGIN_TYPE "geometryloaders")
set_property(TARGET Qt5::DefaultGeometryLoaderPlugin PROPERTY QT_PLUGIN_EXTENDS "")
