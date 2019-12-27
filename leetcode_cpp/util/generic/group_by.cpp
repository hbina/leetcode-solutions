#include "doctest/doctest.h"

#include "group_by.hpp"

#include <vector>
#include <list>

TEST_CASE("util::generic::group_by")
{
    const std::vector<int> input = {1, 1, 2, 4, 6, 5, 7};
    const std::vector<std::vector<int>> expected = {{1, 1}, {2, 4, 6}, {5, 7}};
    const auto result =
        util::generic::group_by<std::vector<std::vector<int>>>(
            input.cbegin(),
            input.cend(),
            [](const int &lhs, const int &rhs) -> bool {
                return (lhs % 2) == (rhs % 2);
            });
    CHECK(expected == result);
}

TEST_CASE("util::generic::group_by")
{
    const std::list<int> input = {1, 1, 2, 4, 6, 5, 7};
    const std::list<std::list<int>> expected = {{1, 1}, {2, 4, 6}, {5, 7}};
    const auto result =
        util::generic::group_by<std::list<std::list<int>>>(
            input.cbegin(),
            input.cend(),
            [](const int &lhs, const int &rhs) -> bool {
                return (lhs % 2) == (rhs % 2);
            });
    CHECK(expected == result);
}
