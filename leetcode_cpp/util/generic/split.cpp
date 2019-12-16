#include "split.hpp"

#include <doctest/doctest.h>

#include <vector>

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    std::vector<int> input = {1, 2, 3, 2, 5};
    std::vector<std::vector<int>> expected = {{1, 2}, {3, 2}, {5}};
    int delimiter = 2;
    std::vector<std::vector<int>> result = util::generic::split<
        std::vector<std::vector<int>>,
        std::vector<int>>(
        input.cbegin(),
        input.cend(),
        delimiter);
    CHECK(expected == result);
}

TEST_CASE("util::generic::split test -- vector<int> --> vector<vector<int>> delimited by some functor")
{
    std::vector<int> input = {1, 2, 3, 2, 5};
    std::vector<std::vector<int>> expected = {{1, 2}, {3, 2}, {5}};
    auto delimiter = [](const int &elem) -> bool {
        return elem % 2 == 0;
    };
    std::vector<std::vector<int>> result = util::generic::split_if<
        std::vector<std::vector<int>>,
        std::vector<int>>(
        input.cbegin(),
        input.cend(),
        delimiter);
    CHECK(expected == result);
}
