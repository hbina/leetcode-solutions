#include "doctest/doctest.h"

#include "../include/problem_1282.hpp"

TEST_CASE("problem_1282")
{
    const std::vector<int> input = {3, 3, 3, 3, 3, 1, 3};
    const std::vector<std::vector<int>> expected = {
        {0, 1, 2},
        {3, 4, 6},
        {5}};
    const std::vector<std::vector<int>>
        result = leetcode::groupThePeople(input);
    CHECK(expected == result);
}

TEST_CASE("problem_1282")
{
    const std::vector<int> input = {2, 1, 3, 3, 3, 2};
    const std::vector<std::vector<int>>
        expected = {{0, 5},
                    {1},
                    {2, 3, 4}};
    const std::vector<std::vector<int>>
        result = leetcode::groupThePeople(input);
    CHECK(expected == result);
}
