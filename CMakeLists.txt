cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(Pomordor LANGUAGES CXX)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(PomordorEngine)
add_subdirectory(PomordorUI)
add_subdirectory(Test)

 