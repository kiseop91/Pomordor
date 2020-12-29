#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QQuickProfilerAdapterFactory" for configuration "Debug"
set_property(TARGET Qt6::QQuickProfilerAdapterFactory APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Qt6::QQuickProfilerAdapterFactory PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./plugins/qmltooling/qmldbg_quickprofilerd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QQuickProfilerAdapterFactory )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QQuickProfilerAdapterFactory "${_IMPORT_PREFIX}/./plugins/qmltooling/qmldbg_quickprofilerd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
