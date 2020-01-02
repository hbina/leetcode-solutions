#include "doctest/doctest.h"

#include "leetcode/problem_394.hpp"

TEST_CASE("problem_394")
{
    CHECK(std::string("aaabcbc") == leetcode::decodeString("3[a]2[bc]"));
    CHECK(std::string("accaccacc") == leetcode::decodeString("3[a2[c]]"));
    CHECK(std::string("abcabccdcdcdef") == leetcode::decodeString("2[abc]3[cd]ef"));
}
