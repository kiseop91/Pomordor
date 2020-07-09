cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(PomordorEngine LANGUAGES CXX)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(project_headers 
    pegpch.h
    Core.h
    Pome.h
    Util.h
    main.h
    Toast.h
)
set(project_source 
    pegpch.cpp
    main.cpp
    Util.cpp
    Toast.cpp
)

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}../vendor/lib)

add_library(${PROJECT_NAME} STATIC ${project_source} ${project_headers} )
target_precompile_headers(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/pegpch.h")
