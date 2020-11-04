cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

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
	src/TimerPage/TimerPage.ui
	src/TimerPage/ScheduleDialog.ui
	src/SplashWidget/splashwidget.ui
	src/TodoPage/TodoPage.ui
	src/MainWindow/mainwindow.ui
)

set(project_headers
	src/pompch.h
	src/TimerPage/Timer.h
	src/TimerPage/TimerPage.h
	src/TimerPage/ScheduleDialog.h
	src/TimerPage/TrayIcon.h
	src/TimerPage/Titlebar.h
	src/SplashWidget/splashwidget.h
	src/TodoPage/TodoPage.h
	src/MainWindow/mainwindow.h
)

set(project_sources 
    src/main.cpp
	src/pompch.cpp
	src/TimerPage/Timer.cpp
	src/TimerPage/TimerPage.cpp
	src/TimerPage/ScheduleDialog.cpp
	src/TimerPage/TrayIcon.cpp
	src/TimerPage/Titlebar.cpp
	src/TodoPage/TodoPage.cpp
	src/SplashWidget/splashwidget.cpp
	src/MainWindow/mainwindow.cpp
)

set(qt_moc_headers
	src/TimerPage/TimerPage.h
	src/TimerPage/ScheduleDialog.h
	src/TimerPage/TrayIcon.h
	src/SplashWidget/splashwidget.h
	src/TodoPage/TodoPage.h
	src/MainWindow/mainwindow.h
)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${qt_moc_headers} )

add_executable(
	${PROJECT_NAME} 
	${project_headers} 
	${project_sources} 
	${project_sources_moc} 
	${project_headers_wrapped} 
	assets/files.qrc
)

set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
    CXX_STANDARD 17
)

target_precompile_headers(
	${PROJECT_NAME} 
	PRIVATE 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/pompch.h"
)

target_include_directories(
	${PROJECT_NAME} 
	PRIVATE 
	${CMAKE_SOURCE_DIR}/PomordorEngine/src
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    PomordorEngine
)

if(false)
	set(WindpOption)
elseif(false)
	set(WindpOption)
endif()

add_custom_command( 
	TARGET ${PROJECT_NAME} 
	COMMAND echo "Create Qt5 dependencies.."
	COMMAND call 
	vendor\\Qt5.14.2\\msvc2017\\bin\\windeployqt.exe
	$(OutputPath)$(TargetName)$(TargetExt)
	${WindpOption}
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
