
add_library(Qt5::QGeoPositionInfoSourceFactoryPoll MODULE IMPORTED)


_populate_Positioning_plugin_properties(QGeoPositionInfoSourceFactoryPoll RELEASE "position/qtposition_positionpoll.dll" TRUE)
_populate_Positioning_plugin_properties(QGeoPositionInfoSourceFactoryPoll DEBUG "position/qtposition_positionpolld.dll" TRUE)

list(APPEND Qt5Positioning_PLUGINS Qt5::QGeoPositionInfoSourceFactoryPoll)
set_property(TARGET Qt5::Positioning APPEND PROPERTY QT_ALL_PLUGINS_position Qt5::QGeoPositionInfoSourceFactoryPoll)
set_property(TARGET Qt5::QGeoPositionInfoSourceFactoryPoll PROPERTY QT_PLUGIN_TYPE "position")
set_property(TARGET Qt5::QGeoPositionInfoSourceFactoryPoll PROPERTY QT_PLUGIN_EXTENDS "")
