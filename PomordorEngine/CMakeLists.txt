cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(PomordorEngine LANGUAGES CXX)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(project_headers 
)
set(project_source 
    main.cpp
)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}../vendor/lib)

add_library(${PROJECT_NAME} STATIC ${project_source} ${project_headers} )

