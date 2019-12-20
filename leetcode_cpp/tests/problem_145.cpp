#include "doctest/doctest.h"

#include "../include/problem_145.hpp"

TEST_CASE("problem_145")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       nullptr,
                       new TreeNode<>(
                           2,
                           new TreeNode<>(
                               3,
                               nullptr,
                               nullptr),
                           nullptr));
    const std::vector<int> expected = {3, 2, 1};
    const std::vector<int> result = leetcode::postorderTraversal(input);
    CHECK(result == expected);
    delete input;
}
