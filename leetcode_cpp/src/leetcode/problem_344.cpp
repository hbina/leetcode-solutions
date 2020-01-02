#include "doctest/doctest.h"

#include "leetcode/problem_344.hpp"

#include <vector>

TEST_CASE("problem_344")
{
    std::vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    const std::vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
    leetcode::reverseString(input);
    CHECK(expected == input);
}

TEST_CASE("problem_344")
{
    std::vector<char> input = {'H', 'a', 'n', 'n', 'a', 'h'};
    const std::vector<char> expected = {'h', 'a', 'n', 'n', 'a', 'H'};
    leetcode::reverseString(input);
    CHECK(expected == input);
}
