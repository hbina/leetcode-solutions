#include "doctest/doctest.h"

#include "leetcode/problem_88.hpp"
#include "util/generic/zip.hpp"

TEST_CASE("problem_88")
{
    const std::vector<int> expected = {1, 2, 2, 3, 5, 6};
    std::vector<int> input_1 = {1, 2, 3, 0, 0, 0};
    const std::vector<int> input_2 = {2, 5, 6};
    leetcode::merge_simple(input_1, 3, input_2, 3);
    CHECK(expected == input_1);
}
