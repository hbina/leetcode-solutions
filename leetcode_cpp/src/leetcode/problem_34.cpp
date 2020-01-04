#include "doctest/doctest.h"

#include "leetcode/problem_34.hpp"

TEST_CASE("problem_34")
{
    const std::vector<int> input_1 = {5, 7, 7, 8, 8, 10};
    const int input_2 = 8;
    const std::vector<int> expected = {3, 4};
    const auto result = leetcode::searchRange(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_34")
{
    const std::vector<int> input_1 = {5, 7, 7, 8, 8, 10};
    const int input_2 = 6;
    const std::vector<int> expected = {-1, -1};
    const auto result = leetcode::searchRange(input_1, input_2);
    CHECK(expected == result);
}
