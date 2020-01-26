#include "doctest/doctest.h"

#include "util/generic/zip_accumulate.hpp"

#include <vector>
#include <list>

TEST_CASE("zip accumulate 1")
{
    const std::vector<int> input_1 = {1, 2, 3, 4, 5};
    const std::vector<int> input_2 = {1, 2, 3, 4, 5};
    const int expected = 55;
    const int result = util::generic::zip_accumulate(
        std::cbegin(input_1),
        std::cend(input_1),
        std::cbegin(input_2),
        std::cend(input_2),
        0,
        [](const auto &lhs, const auto &rhs) -> int {
            return lhs * rhs;
        },
        [](const auto &lhs, const auto &rhs) -> int {
            return lhs + rhs;
        });
    CHECK(expected == result);
}

TEST_CASE("zip accumulate 2")
{
    const std::vector<int> input_1 = {1, 2, 3, 4, 5};
    const std::vector<int> input_2 = {1, 2, 3, 4, 5};
    const bool expected = true;
    const bool result = util::generic::zip_accumulate(
        std::cbegin(input_1),
        std::cend(input_1),
        std::cbegin(input_2),
        std::cend(input_2),
        true,
        [](const auto &lhs, const auto &rhs) -> bool {
            return lhs == rhs;
        },
        [](const auto &lhs, const auto &rhs) -> bool {
            return lhs && rhs;
        });
    CHECK(expected == result);
}

TEST_CASE("zip accumulate 3")
{
    const std::list<int> input_1 = {1, 2, 3, 4, 5};
    const std::list<int> input_2 = {1, 2, 3, 4, 5};
    const bool expected = true;
    const bool result = util::generic::zip_accumulate(
        std::cbegin(input_1),
        std::cend(input_1),
        std::cbegin(input_2),
        std::cend(input_2),
        true,
        [](const auto &lhs, const auto &rhs) -> bool {
            return lhs == rhs;
        },
        [](const auto &lhs, const auto &rhs) -> bool {
            return lhs && rhs;
        });
    CHECK(expected == result);
}
