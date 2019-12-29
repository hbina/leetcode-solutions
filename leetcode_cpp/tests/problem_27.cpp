#include "doctest/doctest.h"

#include "../include/problem_27.hpp"

#include <vector>
#include <list>

TEST_CASE("problem_27")
{
    std::vector<int> input_1 = {3, 2, 2, 3};
    const int input_2 = 3;
    const int expected = 2;
    int result = static_cast<int>(leetcode::removeElement(input_1, input_2));
    CHECK(expected == result);
}

TEST_CASE("problem_27")
{
    std::vector<int> input_1 = {0, 1, 2, 2, 3, 0, 4, 2};
    const int input_2 = 2;
    const int expected = 5;
    int result = static_cast<int>(leetcode::removeElement(input_1, input_2));
    CHECK(expected == result);
}

TEST_CASE("problem_27")
{
    std::vector<int> input_1 = {1, 2, 3, 4};
    const int input_2 = 5;
    const int expected = 4;
    int result = static_cast<int>(leetcode::removeElement(input_1, input_2));
    CHECK(expected == result);
}

TEST_CASE("problem_27")
{
    std::vector<int> input_1;
    const int input_2 = 5;
    const int expected = 0;
    int result = static_cast<int>(leetcode::removeElement(input_1, input_2));
    CHECK(expected == result);
}
