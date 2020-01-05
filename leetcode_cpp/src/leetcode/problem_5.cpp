#include "doctest/doctest.h"

#include "leetcode/problem_5.hpp"

TEST_CASE("problem_5")
{
    const std::string input = "babad";
    const std::string expected = "bab";
    const std::string result = leetcode::longestPalindrome(input);
    CHECK(expected.size() == result.size());
}

TEST_CASE("problem_5")
{
    const std::string input = "abcdasdfghjkldcba";
    const std::string expected = "a";
    const std::string result = leetcode::longestPalindrome(input);
    CHECK(expected.size() == result.size());
}
