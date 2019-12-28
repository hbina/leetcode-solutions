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

    util/generic/reverse_if.cpp
    util/generic/is_number.cpp
    util/generic/find_range.cpp
    util/generic/group_by.cpp
    util/generic/split.cpp
    util/generic/zip.cpp
    
    tests/problem_4.cpp
    tests/problem_14.cpp
    tests/problem_13.cpp
    tests/problem_19.cpp
    tests/problem_21.cpp
    tests/problem_22.cpp
    tests/problem_26.cpp
    tests/problem_394.cpp
    tests/problem_105.cpp
    tests/problem_107.cpp
    tests/problem_145.cpp
    tests/problem_117.cpp
    tests/problem_160.cpp
    tests/problem_88.cpp
    tests/problem_206.cpp
    tests/problem_226.cpp
    tests/problem_297.cpp
    tests/problem_344.cpp
    tests/problem_345.cpp
    tests/problem_371.cpp
    tests/problem_494.cpp
    tests/problem_535.cpp
    tests/problem_536.cpp
    tests/problem_537.cpp
    tests/problem_557.cpp
    tests/problem_589.cpp
    tests/problem_643.cpp
    tests/problem_700.cpp
    tests/problem_888.cpp
    tests/problem_905.cpp
    tests/problem_929.cpp
    tests/problem_938.cpp
    tests/problem_106.cpp
    tests/problem_889.cpp
    tests/problem_965.cpp
    tests/problem_977.cpp
    tests/problem_1010.cpp
    tests/problem_1051.cpp
    tests/problem_1281.cpp
    tests/problem_1221.cpp
    tests/problem_1282.cpp
    tests/problem_1038.cpp
    tests/problem_1283.cpp
    tests/problem_1290.cpp
    )

target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/fmt)
target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/include)
