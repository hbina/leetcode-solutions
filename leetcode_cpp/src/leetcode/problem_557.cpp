#include "doctest/doctest.h"

#include "leetcode/problem_557.hpp"

TEST_CASE("problem_557")
{
    const std::string input = "Let's take leetcode contest";
    const std::string expected = "s'teL ekat edoCteeL tsetnoc";
    const std::string result = leetcode::reverseWords(input);
    CHECK(expected == result);
}
