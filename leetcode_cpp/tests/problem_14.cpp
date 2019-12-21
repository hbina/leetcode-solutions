#include "doctest/doctest.h"

#include "../include/problem_14.hpp"

TEST_CASE("problem_14")
{
    const std::vector<std::string> input = {"flower", "flow", "flight"};
    const std::string expected = "fl";
    const std::string result = leetcode::longestCommonPrefix(input);
    CHECK(expected == result);
}

TEST_CASE("problem_14")
{
    const std::vector<std::string> input = {"", ""};
    const std::string expected = "";
    const std::string result = leetcode::longestCommonPrefix(input);
    CHECK(expected == result);
}

TEST_CASE("problem_14")
{
    const std::vector<std::string> input = {"dog", "racecar", "car"};
    const std::string expected = "";
    const std::string result = leetcode::longestCommonPrefix(input);
    CHECK(expected == result);
}
