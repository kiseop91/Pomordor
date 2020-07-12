cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(PomordorEngine LANGUAGES CXX)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(project_headers 
    pegpch.h
    Core/Core.h
    Pome.h
    Util/Util.h
    main.h
    Toast.h
    Util/PyhtonScript.h
    FileSystem/FileManager.h
    FileSystem/IFile.h
)
set(project_source 
    pegpch.cpp
    main.cpp
    Util/Util.cpp
    Toast.cpp
    Util/PyhtonScript.cpp
    FileSystem/FileManager.cpp
    FileSystem/IFile.cpp
)

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}../vendor/lib)

add_library(${PROJECT_NAME} STATIC ${project_source} ${project_headers} )
target_precompile_headers(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/pegpch.h")
