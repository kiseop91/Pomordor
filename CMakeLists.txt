cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(Pomordor LANGUAGES CXX)
add_compile_options(/std:c++17)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
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

set(JSONCPP_USAGE_LIB ON)

enable_testing()
add_subdirectory(vendor/googletest)
add_subdirectory(vendor/jsoncpp)
add_subdirectory(PomordorEngine)
add_subdirectory(PomordorUI)
add_subdirectory(Tests)