
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was QtModuleToolsConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

include(CMakeFindDependencyMacro)

if (NOT QT_NO_CREATE_TARGETS)
    # Find required dependencies, if any.
    if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/Qt6Quick3DToolsDependencies.cmake")
        include("${CMAKE_CURRENT_LIST_DIR}/Qt6Quick3DToolsDependencies.cmake")
    endif()

    include("${CMAKE_CURRENT_LIST_DIR}/Qt6Quick3DToolsTargets.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/Qt6Quick3DToolsAdditionalTargetInfo.cmake")
    if(NOT QT_NO_CREATE_VERSIONLESS_TARGETS)
        include("${CMAKE_CURRENT_LIST_DIR}/Qt6Quick3DToolsVersionlessTargets.cmake")
    endif()
endif()

foreach(extra_cmake_include )
    include("${CMAKE_CURRENT_LIST_DIR}/${extra_cmake_include}")
endforeach()


if (NOT QT_NO_CREATE_TARGETS)
    get_property(is_global TARGET Qt6::balsam PROPERTY IMPORTED_GLOBAL)
    if(NOT is_global)
        set_property(TARGET Qt6::balsam PROPERTY IMPORTED_GLOBAL TRUE)
    endif()
endif()

if (NOT QT_NO_CREATE_TARGETS)
    get_property(is_global TARGET Qt6::meshdebug PROPERTY IMPORTED_GLOBAL)
    if(NOT is_global)
        set_property(TARGET Qt6::meshdebug PROPERTY IMPORTED_GLOBAL TRUE)
    endif()
endif()

if (NOT QT_NO_CREATE_TARGETS)
    get_property(is_global TARGET Qt6::shadergen PROPERTY IMPORTED_GLOBAL)
    if(NOT is_global)
        set_property(TARGET Qt6::shadergen PROPERTY IMPORTED_GLOBAL TRUE)
    endif()
endif()
set(Qt6Quick3DTools_TARGETS "Qt6::balsam;Qt6::meshdebug;Qt6::shadergen")
