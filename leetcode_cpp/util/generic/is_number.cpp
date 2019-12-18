#include <doctest/doctest.h>

#include "is_number.hpp"

#include <vector>

TEST_CASE("util::string::is_integer ")
{
    std::string input = "0123456789";
    bool expected = true;
    bool result = util::string::is_number(input);
    CHECK(expected == result);
}

TEST_CASE("util::string::is_integer")
{
    std::string input = "4234234g";
    bool expected = false;
    bool result = util::string::is_number(input);
    CHECK(expected == result);
}

TEST_CASE("util::string::is_integer -- using std::vector<char>")
{
    std::vector<char> input = {'1', '2', '3', '4'};
    bool expected = true;
    bool result = util::string::is_number(input);
    CHECK(expected == result);
}
