#include "doctest/doctest.h"

#include "../include/problem_537.hpp"

TEST_CASE("problem_537")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(5,
                       new TreeNode<>(4,
                                      new TreeNode<>(11,
                                                     new TreeNode<>(7),
                                                     new TreeNode<>(2)),
                                      nullptr),
                       new TreeNode<>(8,
                                      new TreeNode<>(13),
                                      new TreeNode<>(4,
                                                     nullptr,
                                                     new TreeNode<>(1))));
    const int input_2 = 22;
    const bool expected = true;
    const bool result = leetcode::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}

TEST_CASE("problem_537")
{
    const TreeNode<> *input_1 = nullptr;
    const int input_2 = 1;
    const bool expected = false;
    const bool result = leetcode::hasPathSum(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_537 -- [1], 0 ==> false")
{
    const TreeNode<> *input_1 = new TreeNode<>(1);
    const int input_2 = 0;
    const bool expected = false;
    const bool result = leetcode::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}

TEST_CASE("problem_537 -- [1,2], 1 ==> true")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(1,
                       new TreeNode<>(2),
                       nullptr);
    const int input_2 = 1;
    const bool expected = false;
    const bool result = leetcode::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}

TEST_CASE("problem_537 -- [-2,null, -3], -5 ==> true")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(-2,
                       nullptr,
                       new TreeNode<>(-3));
    const int input_2 = -5;
    const bool expected = true;
    const bool result = leetcode::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}
