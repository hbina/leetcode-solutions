#include "doctest/doctest.h"

#include "leetcode/problem_4.hpp"

TEST_CASE("problem_4")
{
    const std::vector<int> input_1 = {1, 3};
    const std::vector<int> input_2 = {2};
    CHECK(2.0 == leetcode::findMedianSortedArrays_basic(input_1, input_2));
}

TEST_CASE("problem_4")
{
    const std::vector<int> input_1 = {1, 2};
    const std::vector<int> input_2 = {3, 4};
    CHECK(2.5 == leetcode::findMedianSortedArrays_basic(input_1, input_2));
}
