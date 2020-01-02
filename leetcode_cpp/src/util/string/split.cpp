#include "doctest/doctest.h"

#include "util/string/split.hpp"

#include <vector>

TEST_CASE("util::string::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    std::string input = "hello,world,good,bye,world";
    std::vector<std::string> expected = {"hello", "world", "good", "bye", "world"};
    std::string delimiter = ",";
    CHECK(expected == util::string::split<std::vector<std::string>>(
                          input,
                          delimiter));
}

TEST_CASE("util::string::split test -- vector<int> --> vector<vector<int>> delimited by value 2")
{
    std::string input = "hello.,world.,good.,bye.,world";
    std::vector<std::string> expected = {"hello", "world", "good", "bye", "world"};
    std::string delimiter = ".,";
    std::vector<std::string> result = util::string::split<std::vector<std::string>>(
        input,
        delimiter);
    CHECK(expected == result);
}
