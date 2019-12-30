#include "doctest/doctest.h"

#include "../include/problem_121.hpp"

#include <vector>
#include <list>

TEST_CASE("problem_121")
{
    const std::vector<int> input = {7, 1, 5, 3, 6, 4};
    const int expected = 5;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}

TEST_CASE("problem_121")
{
    const std::list<int> input = {7, 1, 5, 3, 6, 4};
    const int expected = 5;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}

TEST_CASE("problem_121")
{
    const std::list<int> input = {1, 2, 3, 4, 5};
    const int expected = 4;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}

TEST_CASE("problem_121")
{
    const std::list<int> input = {7, 6, 5, 4, 3, 2, 1};
    const int expected = 0;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}

TEST_CASE("problem_121")
{
    const std::list<int> input = {};
    const int expected = 0;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}

TEST_CASE("problem_121")
{
    const std::list<int> input = {7, 10};
    const int expected = 3;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}

TEST_CASE("problem_121")
{
    const std::list<int> input = {10};
    const int expected = 0;
    const int result = leetcode::maxProfit_One(input);
    CHECK(expected == result);
}
