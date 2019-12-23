#include "doctest/doctest.h"

#include "../include/problem_1038.hpp"

TEST_CASE("problem_1038")
{
    TreeNode<> *input =
        new TreeNode<>(4,
                       new TreeNode<>(1,
                                      new TreeNode<>(0),
                                      new TreeNode<>(2,
                                                     nullptr,
                                                     new TreeNode<>(3))),
                       new TreeNode<>(6,
                                      new TreeNode<>(5),
                                      new TreeNode<>(7,
                                                     nullptr,
                                                     new TreeNode<>(8))));
    const TreeNode<> *expected =
        new TreeNode<>(30,
                       new TreeNode<>(36,
                                      new TreeNode<>(36),
                                      new TreeNode<>(35,
                                                     nullptr,
                                                     new TreeNode<>(33))),
                       new TreeNode<>(21,
                                      new TreeNode<>(26),
                                      new TreeNode<>(15,
                                                     nullptr,
                                                     new TreeNode<>(8))));
    const TreeNode<> *result = leetcode::bstToGst(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}
