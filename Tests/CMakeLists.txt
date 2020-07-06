cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

set (This ExampleTests)

set(Sources 
    ExampleTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC 
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
) 

 
 