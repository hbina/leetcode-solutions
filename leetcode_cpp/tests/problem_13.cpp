#include "doctest/doctest.h"

#include "../include/problem_13.hpp"

TEST_CASE("problem_13")
{
    const std::string input = "III";
    const int expected = 3;
    CHECK(expected == leetcode::romanToInt(input));
}

TEST_CASE("problem_13")
{
    const std::string input = "IV";
    const int expected = 4;
    CHECK(expected == leetcode::romanToInt(input));
}

TEST_CASE("problem_13")
{
    const std::string input = "IX";
    const int expected = 9;
    CHECK(expected == leetcode::romanToInt(input));
}

TEST_CASE("problem_13")
{
    const std::string input = "LVIII";
    const int expected = 58;
    CHECK(expected == leetcode::romanToInt(input));
}

TEST_CASE("problem_13")
{
    const std::string input = "MCMXCIV";
    const int expected = 1994;
    CHECK(expected == leetcode::romanToInt(input));
}
