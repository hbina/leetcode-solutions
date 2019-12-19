#include "doctest/doctest.h"

#include "../util/generic/zip.hpp"

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void merge_simple(
    std::vector<T> &lhs, std::size_t m,
    const std::vector<T> &rhs, std::size_t n)
{
    lhs.resize(n);
    lhs.insert(lhs.begin() + m, rhs.cbegin(), rhs.cend());
    std::sort(lhs.begin(), lhs.end());
}

TEST_CASE("problem_88")
{
    const std::vector<int> expected = {1, 2, 2, 3, 5, 6};
    std::vector<int> input_1 = {1, 2, 3, 0, 0, 0};
    const std::vector<int> input_2 = {2, 5, 6};
    merge_simple(input_1, 3, input_2, 3);
    CHECK(expected == input_1);
}
