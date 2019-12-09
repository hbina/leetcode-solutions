cmake_minimum_required (VERSION 3.1)
project (leetcode_solutions)

add_executable(
    leetcode_solutions
    
    main.cpp
    
    util/string_util.cpp

    solutions/problem_145.cpp
    solutions/problem_117.cpp
    solutions/problem_88.cpp
    solutions/problem_226.cpp
    solutions/problem_557.cpp
    solutions/problem_589.cpp
    solutions/problem_643.cpp
    solutions/problem_700.cpp
    solutions/problem_888.cpp
    solutions/problem_905.cpp
    solutions/problem_929.cpp
    solutions/problem_938.cpp
    solutions/problem_965.cpp
    solutions/problem_977.cpp
    solutions/problem_1010.cpp
    solutions/problem_1051.cpp
    )

target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
