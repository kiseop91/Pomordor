cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(PomordorEngine LANGUAGES CXX)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(project_headers 
    src/pegpch.h
    src/Pome.h
    src/Util.h
	src/Clock/Clock.h
)
set(project_source 
    src/pegpch.cpp
    src/Util.cpp
	src/Clock/Clock.cpp
)

if(JSONCPP_USAGE_LIB)
	set(jsoncpp "jsoncpp_static")
elseif(JSONCPP_USAGE_LIB)
	set(jsoncpp "jsoncpp_lib")
endif()

add_library(
	${PROJECT_NAME} 
	STATIC 
	${project_source} 
	${project_headers} 
)

target_link_libraries(
	${PROJECT_NAME} 
	PUBLIC 
	${jsoncpp}
)

target_precompile_headers(
	${PROJECT_NAME} 
	PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/pegpch.h"
)

target_include_directories(
	${PROJECT_NAME} 
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/vendor/jsoncpp/include
)