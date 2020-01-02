#include "doctest/doctest.h"

#include "util/string/split.hpp"
#include "util/generic/is_number.hpp"

#include <vector>

TEST_CASE("util::string::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    const std::string input = "hello,world,good,bye,world";
    const std::vector<std::string> expected = {"hello", "world", "good", "bye", "world"};
    const std::string delimiter = ",";
    const std::vector<std::string> result =
        util::string::split<>(
            input,
            delimiter);
    CHECK(expected == result);
}

TEST_CASE("util::string::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    const std::string input = "hello.,world.,good.,bye.,world";
    const std::vector<std::string> expected = {"hello", "world", "good", "bye", "world"};
    const std::string delimiter = ".,";
    const std::vector<std::string> result =
        util::string::split<>(
            input,
            delimiter);
    CHECK(expected == result);
}
