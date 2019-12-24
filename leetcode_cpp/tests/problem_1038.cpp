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

TEST_CASE("problem_1038")
{
    TreeNode<double> *input =
        new TreeNode<double>(4.0,
                       new TreeNode<double>(1.0,
                                      new TreeNode<double>(0.0),
                                      new TreeNode<double>(2.0,
                                                     nullptr,
                                                     new TreeNode<double>(3.0))),
                       new TreeNode<double>(6.0,
                                      new TreeNode<double>(5.0),
                                      new TreeNode<double>(7.0,
                                                     nullptr,
                                                     new TreeNode<double>(8.0))));
    const TreeNode<double> *expected =
        new TreeNode<double>(30.0,
                       new TreeNode<double>(36.0,
                                      new TreeNode<double>(36.0),
                                      new TreeNode<double>(35.0,
                                                     nullptr,
                                                     new TreeNode<double>(33.0))),
                       new TreeNode<double>(21.0,
                                      new TreeNode<double>(26.0),
                                      new TreeNode<double>(15.0,
                                                     nullptr,
                                                     new TreeNode<double>(8.0))));
    const TreeNode<double> *result = leetcode::bstToGst(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}
