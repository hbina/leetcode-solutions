#include "doctest/doctest.h"

#include "../include/problem_888.hpp"

TEST_CASE("problem_888")
{
    const std::vector<int> input_1{1, 1};
    const std::vector<int> input_2{2, 2};
    const std::vector<int> expected = {1, 2};
    const std::vector<int> result = leetcode::fairCandySwap(input_1, input_2);
    CHECK(expected == result);
}
