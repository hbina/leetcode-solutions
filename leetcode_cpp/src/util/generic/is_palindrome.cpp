#include "doctest/doctest.h"

#include "util/generic/is_palindrome.hpp"

TEST_CASE("is palindrome 1")
{
    const std::string input = "hello";
    const bool expected = false;
    const bool result =
        util::generic::is_palindrome(
            std::cbegin(input),
            std::cend(input));
    CHECK(expected == result);
}

TEST_CASE("is palindrome 2")
{
    const std::string input = "";
    const bool expected = true;
    const bool result =
        util::generic::is_palindrome(
            std::cbegin(input),
            std::cend(input));
    CHECK(expected == result);
}

TEST_CASE("is palindrome 3")
{
    const std::string input = "abba";
    const bool expected = true;
    const bool result =
        util::generic::is_palindrome(
            std::cbegin(input),
            std::cend(input));
    CHECK(expected == result);
}

TEST_CASE("is palindrome 4")
{
    const std::string input = "aa";
    const bool expected = true;
    const bool result =
        util::generic::is_palindrome(
            std::cbegin(input),
            std::cend(input));
    CHECK(expected == result);
}

TEST_CASE("is palindrome 5")
{
    const std::string input = "a";
    const bool expected = true;
    const bool result =
        util::generic::is_palindrome(
            std::cbegin(input),
            std::cend(input));
    CHECK(expected == result);
}
