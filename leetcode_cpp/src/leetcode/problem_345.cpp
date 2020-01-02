#include "doctest/doctest.h"

#include "leetcode/problem_345.hpp"

TEST_CASE("problem_345")
{
    const std::string input = "hello";
    const std::string expected = "holle";
    const std::string result = leetcode::reverseVowels(input);
    CHECK(expected == result);
}

TEST_CASE("problem_345")
{
    const std::string input = "leetcode";
    const std::string expected = "leotcede";
    const std::string result = leetcode::reverseVowels(input);
    CHECK(expected == result);
}

TEST_CASE("problem_345")
{
    const std::string input = "aA";
    const std::string expected = "Aa";
    const std::string result = leetcode::reverseVowels(input);
    CHECK(expected == result);
}
