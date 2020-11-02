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

if(BUILD_PE_STATIC)
	message("Pome - static lib")
	add_library(
		${PROJECT_NAME} 
		STATIC 
		${project_source} 
		${project_headers} 
	)
elseif(BUILD_PE_LIB)
	message("Pome - dll")
	add_library(
		${PROJECT_NAME} 
		SHARED 
		${project_source} 
		${project_headers} 
	)
else()
	message("Nothing chooesd please check pomordor_config.cmake")
endif()

set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
    CXX_STANDARD 17
)

target_link_libraries(
	${PROJECT_NAME} 
	PRIVATE 
	${Jsoncpp}
)

target_precompile_headers(
	${PROJECT_NAME} 
	PRIVATE 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/pegpch.h"
)

target_include_directories(
	${PROJECT_NAME} 
	PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/vendor/jsoncpp/include
)