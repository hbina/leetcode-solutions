#include "doctest/doctest.h"

#include "../include/problem_938.hpp"

TEST_CASE("problem_938")
{
    const TreeNode<> *input =
        new TreeNode<>(10,
                       new TreeNode<>(5,
                                      new TreeNode<>(3),
                                      new TreeNode<>(7)),
                       new TreeNode<>(15,
                                      nullptr,
                                      new TreeNode<>(18)));
    const int expected = 32;
    const int result = leetcode::rangeSumBST_recursion(input, 7, 15);
    CHECK(expected == result);
    delete input;
}
