#include "doctest/doctest.h"

#include "leetcode/problem_5316.hpp"

TEST_CASE("problem_5316")
{
    const std::string input = "HOW ARE YOU";
    const std::vector<std::string> expected = {"HAY", "ORO", "WEU"};
    const std::vector<std::string> result = leetcode::printVertically(input);
    CHECK(expected == result);
}
