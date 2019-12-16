cmake_minimum_required (VERSION 3.1)
project (leetcode_solutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

add_executable(
    leetcode_solutions
    
    main.cpp
    
    util/string/split.cpp
    
    util/generic/is_integer.cpp
    util/generic/split.cpp
    
    solutions/problem_4.cpp
    solutions/problem_394.cpp
    solutions/problem_105.cpp
    solutions/problem_107.cpp
    solutions/problem_145.cpp
    solutions/problem_117.cpp
    solutions/problem_160.cpp
    solutions/problem_88.cpp
    solutions/problem_206.cpp
    solutions/problem_226.cpp
    solutions/problem_297.cpp
    solutions/problem_371.cpp
    solutions/problem_494.cpp
    solutions/problem_535.cpp
    solutions/problem_536.cpp
    solutions/problem_537.cpp
    solutions/problem_557.cpp
    solutions/problem_589.cpp
    solutions/problem_643.cpp
    solutions/problem_700.cpp
    solutions/problem_888.cpp
    solutions/problem_905.cpp
    solutions/problem_929.cpp
    solutions/problem_938.cpp
    solutions/problem_106.cpp
    solutions/problem_889.cpp
    solutions/problem_965.cpp
    solutions/problem_977.cpp
    solutions/problem_1010.cpp
    solutions/problem_1051.cpp
    solutions/problem_1281.cpp
    solutions/problem_1282.cpp
    solutions/problem_1283.cpp
    )

target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/fmt)
