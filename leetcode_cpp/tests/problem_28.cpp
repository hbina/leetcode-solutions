#include "doctest/doctest.h"

#include "../include/problem_28.hpp"

#include <string>
#include <vector>

TEST_CASE("problem_28")
{
    const std::string input_1 = "hello";
    const std::string input_2 = "ll";
    const int expected = 2;
    const int result = leetcode::strStr(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_28")
{
    const std::string input_1 = "aaaaa";
    const std::string input_2 = "bba";
    const int expected = -1;
    const int result = leetcode::strStr(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_28")
{
    const std::string input_1 = "";
    const std::string input_2 = "";
    const int expected = 0;
    const int result = leetcode::strStr(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_28")
{
    const std::string input_1 = "aaaaa";
    const std::string input_2 = "";
    const int expected = 0;
    const int result = leetcode::strStr(input_1, input_2);
    CHECK(expected == result);
}
