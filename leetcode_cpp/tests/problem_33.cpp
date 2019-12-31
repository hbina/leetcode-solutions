#include "doctest/doctest.h"

#include "../include/problem_33.hpp"

#include <vector>
#include <list>

TEST_CASE("problem_33")
{
    const std::vector<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 0;
    const int expected = 4;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::vector<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 3;
    const int expected = -1;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::list<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 0;
    const int expected = 4;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::list<int> input_1 = {4, 5, 6, 7, 0, 1, 2};
    const int input_2 = 3;
    const int expected = -1;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::vector<int> input_1;
    const int input_2 = 3;
    const int expected = -1;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::list<int> input_1;
    const int input_2 = 3;
    const int expected = -1;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::vector<int> input_1 = {1, 3};
    const int input_2 = 2;
    const int expected = -1;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_33")
{
    const std::vector<int> input_1 = {2, 3};
    const int input_2 = 0;
    const int expected = -1;
    const int result = leetcode::search(input_1, input_2);
    CHECK(expected == result);
}
