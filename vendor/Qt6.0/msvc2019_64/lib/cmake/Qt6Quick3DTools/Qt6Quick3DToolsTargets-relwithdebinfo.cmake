#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::balsam" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::balsam APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::balsam PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/balsam.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::balsam )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::balsam "${_IMPORT_PREFIX}/bin/balsam.exe" )

# Import target "Qt6::meshdebug" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::meshdebug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::meshdebug PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/meshdebug.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::meshdebug )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::meshdebug "${_IMPORT_PREFIX}/bin/meshdebug.exe" )

# Import target "Qt6::shadergen" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::shadergen APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::shadergen PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/shadergen.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::shadergen )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::shadergen "${_IMPORT_PREFIX}/bin/shadergen.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
