#include "doctest/doctest.h"

#include "leetcode/problem_226.hpp"

TEST_CASE("problem__226")
{
    TreeNode<> *input =
        new TreeNode<>(4,
                       new TreeNode<>(
                           2,
                           new TreeNode<>(1),
                           new TreeNode<>(3)),
                       new TreeNode<>(7,
                                      new TreeNode<>(6),
                                      new TreeNode<>(9)));
    const TreeNode<int> *expected =
        new TreeNode<>(4,
                       new TreeNode<>(
                           7,
                           new TreeNode<>(9),
                           new TreeNode<>(6)),
                       new TreeNode<>(2,
                                      new TreeNode<>(3),
                                      new TreeNode<>(1)));
    const TreeNode<> *result = leetcode::invertTree(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}
