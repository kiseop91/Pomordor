#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Core_qobject" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::Core_qobject APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::Core_qobject PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/Qt6Core_qobject.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Core_qobject )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Core_qobject "${_IMPORT_PREFIX}/lib/Qt6Core_qobject.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
