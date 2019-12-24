#include "doctest/doctest.h"

#include "reverse_if.hpp"

#include <string>

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "h4ll5";
    std::string expected = "h5ll4";
    util::generic::reverse_if(input.begin(), input.end(), std::isdigit);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "hh";
    std::string expected = "hh";
    util::generic::reverse_if(input.begin(), input.end(), std::isdigit);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "34";
    std::string expected = "43";
    util::generic::reverse_if(input.begin(), input.end(), std::isdigit);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "";
    std::string expected = "";
    util::generic::reverse_if(input.begin(), input.end(), std::isdigit);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "3";
    std::string expected = "3";
    util::generic::reverse_if(input.begin(), input.end(), std::isdigit);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "4";
    std::string expected = "4";
    util::generic::reverse_if(input.begin(), input.end(), std::isdigit);
}
