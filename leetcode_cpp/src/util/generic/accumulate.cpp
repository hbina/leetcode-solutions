#include "doctest/doctest.h"

#include "util/generic/accumulate.hpp"

#include <string>

TEST_CASE("util::generic::accumulate")
{
    const auto result =
        util::generic::accumulate(
            0, 9,
            0,
            [](const int &acc, const auto &index)
                -> int {
                return acc + 1;
            });
    const auto expected = 9;
    CHECK(expected == result);
}

TEST_CASE("util::generic::accumulate")
{
    const auto result =
        util::generic::accumulate(
            0, 9,
            std::string{},
            [](const std::string &acc, const auto &index)
                -> std::string {
                return acc + std::to_string(index);
            });
    const std::string expected = "012345678";
    CHECK(expected == result);
}
