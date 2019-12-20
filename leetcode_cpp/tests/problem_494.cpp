#include "doctest/doctest.h"

#include "../include/problem_494.hpp"

TEST_CASE("problem_494")
{
    const std::vector<int> input_1 = {1, 1, 1, 1, 1};
    const int input_2 = 3;
    const int expected = 5;
    const int result_bruteForce = static_cast<int>(leetcode::findTargetSumWays_bruteForce(input_1, input_2));
    const int result_memoization = static_cast<int>(leetcode::findTargetSumWays_memoization(input_1, input_2));
    CHECK(expected == result_bruteForce);
    CHECK(expected == result_memoization);
}

TEST_CASE("problem_494 -- long input")
{
    const std::vector<int> input_1 = {30, 1, 5, 32, 16, 17, 30, 29, 48, 14, 29, 4, 31, 12, 40, 13, 13, 20, 41, 38};
    const int input_2 = 9;
    const int expected = 6867;
    const int result_bruteForce = static_cast<int>(leetcode::findTargetSumWays_bruteForce(input_1, input_2));
    const int result_memoization = static_cast<int>(leetcode::findTargetSumWays_memoization(input_1, input_2));
    CHECK(expected == result_bruteForce);
    CHECK(expected == result_memoization);
}

TEST_CASE("problem_494 -- long input 2")
{
    const std::vector<int> input_1 = {25, 14, 16, 44, 9, 22, 15, 27, 23, 10, 41, 25, 14, 35, 28, 47, 39, 26, 11, 38};
    const int input_2 = 43;
    const int expected = 6182;
    const int result_bruteForce = static_cast<int>(leetcode::findTargetSumWays_bruteForce(input_1, input_2));
    const int result_memoization = static_cast<int>(leetcode::findTargetSumWays_memoization(input_1, input_2));
    CHECK(expected == result_bruteForce);
    CHECK(expected == result_memoization);
}
