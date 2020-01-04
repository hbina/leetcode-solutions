#include "doctest/doctest.h"

#include "leetcode/problem_35.hpp"

TEST_CASE("problem_35")
{
    const std::vector<int> input_1 = {1, 3, 5, 6};
    const int input_2 = 5;
    const std::vector<int>::difference_type expected = 2;
    const auto result = leetcode::searchInsert(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_35")
{
    const std::vector<int> input_1 = {1, 3, 5, 6};
    const int input_2 = 2;
    const std::vector<int>::difference_type expected = 1;
    const auto result = leetcode::searchInsert(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_35")
{
    const std::vector<int> input_1 = {1, 3, 5, 6};
    const int input_2 = 0;
    const std::vector<int>::difference_type expected = 0;
    const auto result = leetcode::searchInsert(input_1, input_2);
    CHECK(expected == result);
}
