#include "doctest/doctest.h"

#include "util/generic/group_by.hpp"

#include <vector>
#include <list>
#include <string>

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

TEST_CASE("util::generic::group_by")
{
    const std::list<int> input = {1, 1, 2, 4, 6, 5, 7};
    const std::vector<std::list<int>> expected = {{1, 1}, {2, 4, 6}, {5, 7}};
    const auto result =
        util::generic::group_by<std::vector<std::list<int>>>(
            input.cbegin(),
            input.cend(),
            [](const int &lhs, const int &rhs) -> bool {
                return (lhs % 2) == (rhs % 2);
            });
    CHECK(expected == result);
}

TEST_CASE("util::generic::group_by")
{
    const std::string input = "123123hello3213213world";
    const std::vector<std::string> expected = {"123123", "hello", "3213213", "world"};
    const auto result =
        util::generic::group_by<std::vector<std::string>>(
            input.cbegin(),
            input.cend(),
            [](const auto &lhs, const auto &rhs) -> bool {
                return std::isalpha(lhs) == std::isalpha(rhs);
            });
    CHECK(expected == result);
}

TEST_CASE("util::generic::group_by")
{
    const std::string input = "hh123123hello3213213world33";
    const std::vector<std::string> expected = {"hh", "123123", "hello", "3213213", "world", "33"};
    const auto result =
        util::generic::group_by<std::vector<std::string>>(
            input.cbegin(),
            input.cend(),
            [](const auto &lhs, const auto &rhs) -> bool {
                return std::isalpha(lhs) == std::isalpha(rhs);
            });
    CHECK(expected == result);
}
