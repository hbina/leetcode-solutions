#include "doctest/doctest.h"

#include "../include/problem_1051.hpp"

TEST_CASE("problem_1051")
{
    const std::vector<int> input = {1, 1, 4, 2, 1, 3};
    const int expected = 3;
    const int result = static_cast<int>(leetcode::heightChecker(input));
    const int result_zip = static_cast<int>(leetcode::heightChecker_zip(input));
    CHECK(expected == result);
    CHECK(expected == result_zip);
}
