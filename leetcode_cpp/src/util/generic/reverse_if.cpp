#include "doctest/doctest.h"

#include "util/generic/reverse_if.hpp"

#include <string>
#include <vector>
#include <cctype>

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "h4ll5";
    std::string expected = "h5ll4";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isdigit(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 4, 3, 2, 5};
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const int &x) -> bool {
            return x % 2 == 0;
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "hh";
    std::string expected = "hh";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isdigit(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::vector<char> input = {'h', 'g'};
    std::vector<char> expected = {'g', 'h'};
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isalpha(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "34";
    std::string expected = "43";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isdigit(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "";
    std::string expected = "";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isdigit(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "3";
    std::string expected = "3";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isdigit(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "4";
    std::string expected = "4";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const char &x) -> bool {
            return std::isdigit(static_cast<int>(x));
        });
    CHECK(expected == input);
}

TEST_CASE("util::generic::reverse_if")
{
    std::string input = "hegxo";
    std::string expected = "oxgeh";
    util::generic::reverse_if(
        input.begin(),
        input.end(),
        [](const auto &) -> bool {
            return true;
        });
    CHECK(expected == input);
}