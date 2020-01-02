#include "doctest/doctest.h"

#include "leetcode/problem_536.hpp"

TEST_CASE("problem_536")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       new TreeNode<>(2,
                                      new TreeNode<>(3),
                                      new TreeNode<>(4)),
                       new TreeNode<>(2,
                                      new TreeNode<>(4),
                                      new TreeNode<>(3)));
    bool expected = true;
    bool result = leetcode::isSymmetric(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       new TreeNode<>(2,
                                      new TreeNode<>(3),
                                      new TreeNode<>(2)),
                       new TreeNode<>(2,
                                      new TreeNode<>(4),
                                      new TreeNode<>(3)));
    const bool expected = false;
    bool result = leetcode::isSymmetric(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input = new TreeNode<>(1);
    const bool expected = true;
    bool result = leetcode::isSymmetric(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input = nullptr;
    const bool expected = true;
    bool result = leetcode::isSymmetric(input);
    CHECK(expected == result);
}
