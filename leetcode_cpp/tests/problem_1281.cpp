#include "doctest/doctest.h"

#include "../include/problem_1281.hpp"

TEST_CASE("problem_1281")
{
    CHECK(15 == leetcode::subtractProductAndSum(234));
    CHECK(21 == leetcode::subtractProductAndSum(4421));
}
