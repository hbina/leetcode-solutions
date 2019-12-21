#include "doctest/doctest.h"

#include "find_range.hpp"

#include <vector>

TEST_CASE("find_range")
{
    const std::string input = "abcXYZfghijklmnopqrstuvwxyz";
    const std::string delimiter = "XYZ";
    const auto expected = input.cbegin() + 3;
    const auto result = util::generic::find_range(
        input.cbegin(),
        input.cend(),
        delimiter.cbegin(),
        delimiter.cend());
    CHECK(expected == result);
}

TEST_CASE("find_range")
{
    const std::vector<int> input = {1, 2, 3, 4, 5, 6};
    const std::vector<int> delimiter = {3, 4};
    const auto expected = input.cbegin() + 2;
    const auto result = util::generic::find_range(
        input.cbegin(),
        input.cend(),
        delimiter.cbegin(),
        delimiter.cend());
    CHECK(expected == result);
}

TEST_CASE("find_range")
{
    const std::string input = "abcXYZ";
    const std::string delimiter = "XYZ";
    const auto expected = input.cbegin() + 3;
    const auto result = util::generic::find_range(
        input.cbegin(),
        input.cend(),
        delimiter.cbegin(),
        delimiter.cend());
    CHECK(expected == result);
}

TEST_CASE("find_range")
{
    const std::string input = "XYZ";
    const std::string delimiter = "XYZ";
    const auto expected = input.cbegin();
    const auto result = util::generic::find_range(
        input.cbegin(),
        input.cend(),
        delimiter.cbegin(),
        delimiter.cend());
    CHECK(expected == result);
}

TEST_CASE("find_range")
{
    const std::string input = "abcXZ";
    const std::string delimiter = "XYZ";
    const auto expected = input.cbegin() + 5;
    const auto result = util::generic::find_range(
        input.cbegin(),
        input.cend(),
        delimiter.cbegin(),
        delimiter.cend());
    CHECK(expected == result);
}
