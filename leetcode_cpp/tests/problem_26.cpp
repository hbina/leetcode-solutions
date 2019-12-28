#include "doctest/doctest.h"

#include "../include/problem_26.hpp"

#include <vector>
#include <list>

TEST_CASE("problem_26")
{
    std::vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    const int expected = 5;
    int result = static_cast<int>(leetcode::removeDuplicates(input));
    CHECK(expected == result);
}

TEST_CASE("problem_26")
{
    std::vector<int> input = {1, 1, 2};
    const int expected = 2;
    int result = static_cast<int>(leetcode::removeDuplicates(input));
    CHECK(expected == result);
}

TEST_CASE("problem_26")
{
    std::vector<int> input = {1, 1, 1};
    const int expected = 1;
    int result = static_cast<int>(leetcode::removeDuplicates(input));
    CHECK(expected == result);
}

TEST_CASE("problem_26")
{
    std::list<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    const int expected = 5;
    int result = static_cast<int>(leetcode::removeDuplicates(input));
    CHECK(expected == result);
}
