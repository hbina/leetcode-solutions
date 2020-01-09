#include "doctest/doctest.h"

#include "leetcode/problem_38.hpp"

TEST_CASE("problem_38")
{
    const int input = 1;
    const std::string expected = "1";
    const std::string result = leetcode::countAndSay(input);
    CHECK(expected == result);
}

TEST_CASE("problem_38")
{
    const int input = 4;
    const std::string expected = "1211";
    const std::string result = leetcode::countAndSay(input);
    CHECK(expected == result);
}
