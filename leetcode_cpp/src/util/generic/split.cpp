#include "doctest/doctest.h"

#include "util/generic/split.hpp"

#include <vector>
#include <cctype>

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    const std::vector<int> input = {1, 2, 2, 3, 2, 4, 5};
    const std::vector<std::vector<int>> expected = {{1}, {3}, {4, 5}};
    const int delimiter = 2;
    const auto result =
        util::generic::split<int>(
            std::cbegin(input),
            std::cend(input),
            delimiter);
    CHECK(expected == result);
}

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by some functor")
{
    const std::vector<int> input = {1, 2, 3, 4, 5};
    const std::vector<std::vector<int>> expected = {{1}, {3}, {5}};
    const auto result =
        util::generic::split_if<int>(
            std::cbegin(input),
            std::cend(input),
            [](const int &elem) -> bool {
                return elem % 2 == 0;
            });
    CHECK(expected == result);
}

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by some functor")
{
    const std::vector<int> input = {1, 3, 5};
    const std::vector<std::vector<int>> expected = {{1, 3, 5}};
    const auto result =
        util::generic::split_if<int>(
            std::cbegin(input),
            std::cend(input),
            [](const int &elem) -> bool {
                return elem % 2 == 0;
            });
    CHECK(expected == result);
}

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by some functor")
{
    const std::vector<int> input = {2, 1, 2, 3, 4, 5, 6};
    const std::vector<std::vector<int>> expected = {{1}, {3}, {5}};
    const auto result =
        util::generic::split_if<int>(
            std::cbegin(input),
            std::cend(input),
            [](const int &elem) -> bool {
                return elem % 2 == 0;
            });
    CHECK(expected == result);
}

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by some functor")
{
    const std::vector<int> input = {2, 2, 1, 2, 4, 3, 4, 8, 10, 5, 6};
    const std::vector<std::vector<int>> expected = {{1}, {3}, {5}};
    const auto result =
        util::generic::split_if<int>(
            std::cbegin(input),
            std::cend(input),
            [](const int &elem) -> bool {
                return elem % 2 == 0;
            });
    CHECK(expected == result);
}

TEST_CASE("util::string::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    const std::string input = "hello43world233good333bye123world";
    const std::vector<std::string> expected = {"hello", "world", "good", "bye", "world"};
    const std::vector<std::string> result =
        util::generic::split_if<
            std::string::value_type,
            std::string>(
            std::cbegin(input),
            std::cend(input),
            [](const auto &value) -> bool {
                return std::isdigit(value);
            });
    CHECK(expected == result);
}
