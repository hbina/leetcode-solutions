#include "doctest/doctest.h"

#include "util/generic/set_equality.hpp"

#include <vector>
#include <list>

TEST_CASE("util::generic::set_equality 1")
{
    const std::vector<int> input_1 = {1, 2, 3, 4, 5, 6};
    const std::vector<int> input_2 = {6, 5, 4, 3, 2, 1};
    const bool expected = true;
    CHECK(expected == util::generic::set_equality(
                          std::cbegin(input_1),
                          std::cend(input_1),
                          std::cbegin(input_2),
                          std::cend(input_2)));
}

TEST_CASE("util::generic::set_equality 2")
{
    const std::vector<int> input_1 = {1, 2, 3, 4, 5, 6};
    const std::vector<int> input_2 = {6, 5, 4, 3, 2, 1, 7};
    const bool expected = false;
    CHECK(expected == util::generic::set_equality(
                          std::cbegin(input_1),
                          std::cend(input_1),
                          std::cbegin(input_2),
                          std::cend(input_2)));
}

TEST_CASE("util::generic::set_equality 3")
{
    const std::vector<int> input_1 = {};
    const std::vector<int> input_2 = {};
    const bool expected = true;
    CHECK(expected == util::generic::set_equality(
                          std::cbegin(input_1),
                          std::cend(input_1),
                          std::cbegin(input_2),
                          std::cend(input_2)));
}

TEST_CASE("util::generic::set_equality 3")
{
    const std::list<int> input_1 = {1, 2, 3, 4};
    const std::list<int> input_2 = {4, 3, 2, 1};
    const bool expected = true;
    CHECK(expected == util::generic::set_equality(
                          std::cbegin(input_1),
                          std::cend(input_1),
                          std::cbegin(input_2),
                          std::cend(input_2)));
}
