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

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(
    leetcode_solutions
    
    src/main.cpp
    
    src/util/string/split.cpp

    src/util/generic/reverse_if.cpp
    src/util/generic/is_number.cpp
    src/util/generic/find_range.cpp
    src/util/generic/set_equality.cpp
    src/util/generic/group_by.cpp
    src/util/generic/split.cpp
    src/util/generic/zip.cpp
    
    src/leetcode/problem_4.cpp
    src/leetcode/problem_14.cpp
    src/leetcode/problem_13.cpp
    src/leetcode/problem_19.cpp
    src/leetcode/problem_21.cpp
    src/leetcode/problem_22.cpp
    src/leetcode/problem_24.cpp
    src/leetcode/problem_26.cpp
    src/leetcode/problem_27.cpp
    src/leetcode/problem_28.cpp
    src/leetcode/problem_30.cpp
    src/leetcode/problem_33.cpp
    src/leetcode/problem_35.cpp
    src/leetcode/problem_81.cpp
    src/leetcode/problem_121.cpp
    src/leetcode/problem_122.cpp
    src/leetcode/problem_394.cpp
    src/leetcode/problem_105.cpp
    src/leetcode/problem_107.cpp
    src/leetcode/problem_145.cpp
    src/leetcode/problem_117.cpp
    src/leetcode/problem_173.cpp
    src/leetcode/problem_160.cpp
    src/leetcode/problem_203.cpp
    src/leetcode/problem_88.cpp
    src/leetcode/problem_206.cpp
    src/leetcode/problem_226.cpp
    src/leetcode/problem_297.cpp
    src/leetcode/problem_344.cpp
    src/leetcode/problem_345.cpp
    src/leetcode/problem_371.cpp
    src/leetcode/problem_494.cpp
    src/leetcode/problem_535.cpp
    src/leetcode/problem_536.cpp
    src/leetcode/problem_537.cpp
    src/leetcode/problem_557.cpp
    src/leetcode/problem_589.cpp
    src/leetcode/problem_643.cpp
    src/leetcode/problem_700.cpp
    src/leetcode/problem_888.cpp
    src/leetcode/problem_905.cpp
    src/leetcode/problem_929.cpp
    src/leetcode/problem_938.cpp
    src/leetcode/problem_106.cpp
    src/leetcode/problem_889.cpp
    src/leetcode/problem_965.cpp
    src/leetcode/problem_977.cpp
    src/leetcode/problem_1010.cpp
    src/leetcode/problem_1051.cpp
    src/leetcode/problem_1281.cpp
    src/leetcode/problem_1221.cpp
    src/leetcode/problem_1282.cpp
    src/leetcode/problem_1038.cpp
    src/leetcode/problem_1283.cpp
    src/leetcode/problem_1290.cpp
    src/leetcode/problem_1304.cpp
    src/leetcode/problem_1305.cpp
)

target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
target_include_directories(leetcode_solutions PRIVATE ${CMAKE_SOURCE_DIR}/fmt)
