#include "doctest/doctest.h"

#include "leetcode/problem_929.hpp"

TEST_CASE("problem_929")
{
    const std::vector<std::string> input = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    const int expected = 2;
    const int result = leetcode::numUniqueEmails(input);
    CHECK(expected == result);
}
