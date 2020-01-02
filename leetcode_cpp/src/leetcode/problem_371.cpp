#include "doctest/doctest.h"

#include "leetcode/problem_371.hpp"

TEST_CASE("problem_371")
{
    CHECK(3 == leetcode::getSum(1, 2));
    CHECK(7 == leetcode::getSum(5, 2));
    CHECK(-1 == leetcode::getSum(-3, 2));
    CHECK(8 == leetcode::getSum(10, -2));
    CHECK(5 == leetcode::getSum(3, 2));
    CHECK(-11 == leetcode::getSum(-11, 0));
    CHECK(0 == leetcode::getSum(0, 0));
    CHECK(0 == leetcode::getSum(-1, 1));
}
