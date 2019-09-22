cmake_minimum_required (VERSION 3.1)
project (leetcode_solutions)

add_executable(
    leetcode_solutions
    
    main.cpp
    
    util/string_util.cpp

    solutions/problem_88.hpp
    solutions/problem_226.hpp
    solutions/problem_557.hpp
    solutions/problem_589.hpp
    solutions/problem_643.hpp
    solutions/problem_700.hpp
    solutions/problem_905.hpp
    solutions/problem_929.hpp
    solutions/problem_938.hpp
    solutions/problem_965.hpp
    solutions/problem_977.hpp
    )

target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
