#include "doctest/doctest.h"

#include "../include/problem_81.hpp"

#include <vector>
#include <list>

TEST_CASE("problem_81")
{
    std::vector<int> input_1 = {2, 5, 6, 0, 0, 1, 2};
    const int input_2 = 0;
    const bool expected = true;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::vector<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 3;
    const bool expected = false;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::list<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 0;
    const bool expected = true;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::list<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 3;
    const bool expected = false;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::vector<int> input_1;
    const int input_2 = 3;
    const bool expected = false;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::list<int> input_1;
    const int input_2 = 3;
    const bool expected = false;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::vector<int> input_1 = {1, 3};
    const int input_2 = 2;
    const bool expected = false;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_81")
{
    std::vector<int> input_1 = {2, 3};
    const int input_2 = 0;
    const bool expected = false;
    const bool result = leetcode::search_TypeTwo(input_1, input_2);
    CHECK(expected == result);
}
