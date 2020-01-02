#include "doctest/doctest.h"

#include "leetcode/problem_1221.hpp"

TEST_CASE("problem_1221")
{
    const std::string input = "RLRRLLRLRL";
    const int output = 4;
    const std::size_t result = static_cast<int>(leetcode::balancedStringSplit(input));
    CHECK(output == result);
}

TEST_CASE("problem_1221")
{
    const std::string input = "RLLLLRRRLR";
    const int output = 3;
    const std::size_t result = static_cast<int>(leetcode::balancedStringSplit(input));
    CHECK(output == result);
}

TEST_CASE("problem_1221")
{
    const std::string input = "LLLLRRRR";
    const int output = 1;
    const std::size_t result = static_cast<int>(leetcode::balancedStringSplit(input));
    CHECK(output == result);
}

TEST_CASE("problem_1221")
{
    const std::string input = "RLRRRLLRLL";
    const int output = 2;
    const std::size_t result = static_cast<int>(leetcode::balancedStringSplit(input));
    CHECK(output == result);
}
