cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(Pomordor LANGUAGES CXX)

# Update submodules as needed
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#set config
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(jsoncpp_config)
include(googletest_config)
include(pomordor_config)
enable_testing()

#Add subdirectories
add_subdirectory(vendor)
add_subdirectory(PomordorEngine)
add_subdirectory(PomordorUI)
add_subdirectory(Tests)

#define solution folder structure
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(VendorProj 
	${Jsoncpp} 
	${GTestProj}
)

set_target_properties(
	${PomordorProj} PROPERTIES FOLDER Pomodor
)

set_target_properties(
	${VendorProj} PROPERTIES FOLDER Vendor
)

#define dependencies
add_dependencies(PomordorEngine ${Jsoncpp})
add_dependencies(PomordorUI PomordorEngine)
