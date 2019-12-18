#include "doctest/doctest.h"

#include "zip.hpp"

#include <vector>
#include <iostream>

TEST_CASE("util::generic::zip test")
{
    const std::vector<int> left = {0, 1, 2, 3, 4};
    const std::vector<int> right = {4, 3, 2, 1, 0};
    const std::size_t expected = 1;
    std::size_t counter = 0;
    util::generic::zip(
        left.cbegin(),
        left.cend(),
        right.cbegin(),
        right.cend(),
        [&](const auto &left, const auto &right) {
            if (left == right)
                counter++;
        });
    CHECK(counter == expected);
}
