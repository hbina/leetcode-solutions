#include "doctest/doctest.h"

#include "leetcode/problem_977.hpp"

TEST_CASE("problem_977")
{
    std::vector<int> input = {-4, -1, 0, 3, 10};
    const std::vector<int> expected = {0, 1, 9, 16, 100};
    const std::vector<int> result = leetcode::sortedSquares(input);
    CHECK(expected == result);
}

TEST_CASE("problem_977")
{
    std::vector<int> input = {-7, -3, 2, 3, 11};
    const std::vector<int> expected = {4, 9, 9, 49, 121};
    const std::vector<int> result = leetcode::sortedSquares(input);
    CHECK(expected == result);
}
