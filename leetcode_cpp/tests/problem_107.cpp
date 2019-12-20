#include "doctest/doctest.h"

#include "../include/problem_107.hpp"

TEST_CASE("problem_107")
{
    const TreeNode<> *input =
        new TreeNode<>(3,
                       new TreeNode<>(9),
                       new TreeNode<>(20,
                                      new TreeNode<>(15),
                                      new TreeNode<>(7)));
    const std::vector<std::vector<int>> expected = {
        {3},
        {9, 20},
        {15, 7}};
    const std::vector<std::vector<int>> result = leetcode::levelOrderBottom(input);
    CHECK(expected == result);
    delete input;
}
