#include "doctest/doctest.h"

#include "leetcode/problem_31.hpp"

#include <vector>

TEST_CASE("problem_31")
{
    std::vector<int> input = {1, 2, 3};
    const std::vector<int> expected = {1, 3, 2};
    leetcode::nextPermutation(input);
    CHECK(expected == input);
}