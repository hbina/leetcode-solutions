#include "doctest/doctest.h"

#include "../include/problem_105.hpp"

TEST_CASE("problem_105")
{
    const std::vector<int> input_1 = {3, 9, 20, 15, 7};
    const std::vector<int> input_2 = {9, 3, 15, 20, 7};
    const TreeNode<> *expected =
        new TreeNode<>(3,
                       new TreeNode<>(9),
                       new TreeNode<>(20,
                                      new TreeNode<>(15),
                                      new TreeNode<>(7)));
    const TreeNode<> *result = leetcode::buildTreePreIn(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
