#include "doctest/doctest.h"

#include "leetcode/problem_5319.hpp"

TEST_CASE("problem 5319 1")
{
    const std::string input = "ababa";
    const int expected = 1;
    const int result = leetcode::removePalindromeSub(input);
    CHECK(expected == result);
}

TEST_CASE("problem 5319 2")
{
    const std::string input = "ababaa";
    const int expected = 2;
    const int result = leetcode::removePalindromeSub(input);
    CHECK(expected == result);
}

TEST_CASE("problem 5319 3")
{
    const std::string input = "";
    const int expected = 0;
    const int result = leetcode::removePalindromeSub(input);
    CHECK(expected == result);
}
