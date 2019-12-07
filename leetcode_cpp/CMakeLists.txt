cmake_minimum_required (VERSION 3.1)
project (leetcode_solutions)

add_executable(
    leetcode_solutions
    
    main.cpp
    
    util/string_util.cpp
    )

target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
