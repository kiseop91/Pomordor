cmake_minimum_required(VERSION 3.16.4 FATAL_ERROR)

project(PomordorUI LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

if(MSVC)
# Instruct CMake where to find cmake related stuffs
set (CMAKE_PREFIX_PATH "..\\vendor\\Qt5.14.2\\msvc2017")

# Set QTDIR to Qt5 SDK path
set (QTDIR "../Qt5.14.2/msvc2017/")
set (RUN_ENV "PATH=${QTDIR}/bin")
MESSAGE ("-- RUN_ENV: ${RUN_ENV}")
endif(MSVC)


find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

set(project_ui
    mainwindow.ui    
)

set(project_headers
    mainwindow.h
    Popup.h
    pompch.h
)

set(project_sources 
    main.cpp
    mainwindow.cpp
    Popup.cpp
    pompch.cpp
)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers} )

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources} ${project_sources_moc} ${project_headers_wrapped} files.qrc)

#Add precomplied header
target_precompile_headers(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/pompch.h")

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)