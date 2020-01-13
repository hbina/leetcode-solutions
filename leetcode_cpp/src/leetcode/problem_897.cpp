#include "doctest/doctest.h"

#include "leetcode/problem_897.hpp"

TEST_CASE("problem_897")
{
    TreeNode<> *input =
        new TreeNode<>(5,
                       new TreeNode<>(3,
                                      new TreeNode<>(2,
                                                     new TreeNode<>(1),
                                                     nullptr),
                                      new TreeNode<>(4)),
                       new TreeNode<>(6,
                                      nullptr,
                                      new TreeNode<>(8,
                                                     new TreeNode<>(7),
                                                     new TreeNode<>(9))));
    const TreeNode<> *expected =
        new TreeNode<>(1,
                       nullptr,
                       new TreeNode<>(2,
                                      nullptr,
                                      new TreeNode<>(3,
                                                     nullptr,
                                                     new TreeNode<>(4,
                                                                    nullptr,
                                                                    new TreeNode<>(5,
                                                                                   nullptr,
                                                                                   new TreeNode<>(6,
                                                                                                  nullptr,
                                                                                                  new TreeNode<>(7,
                                                                                                                 nullptr,
                                                                                                                 new TreeNode<>(8,
                                                                                                                                nullptr,
                                                                                                                                new TreeNode<>(9)))))))));
    delete input;
    delete expected;
}
