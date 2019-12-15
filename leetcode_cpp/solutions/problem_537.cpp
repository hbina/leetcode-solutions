#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
bool hasPathSum(TreeNode<T> *root, int sum)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (!root->left && !root->right && sum == root->val)
    {
        return true;
    }
    else
    {
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
}

TEST_CASE("Problem 537")
{
    TreeNode<> *input_1 = new TreeNode<>(5,
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
    int input_2 = 22;
    bool expected = true;
    CHECK(expected == hasPathSum(input_1, input_2));
}

TEST_CASE("Problem 537")
{
    TreeNode<> *input_1 = nullptr;
    int input_2 = 1;
    bool expected = false;
    CHECK(expected == hasPathSum(input_1, input_2));
}

TEST_CASE("Problem 537 -- [1], 0 ==> false")
{
    TreeNode<> *input_1 = new TreeNode<>(1);
    int input_2 = 0;
    bool expected = false;
    CHECK(expected == hasPathSum(input_1, input_2));
}

TEST_CASE("Problem 537 -- [1,2], 1 ==> true")
{
    TreeNode<> *input_1 = new TreeNode<>(1,
                                               new TreeNode<>(2),
                                               nullptr);
    int input_2 = 1;
    bool expected = false;
    CHECK(expected == hasPathSum(input_1, input_2));
}

TEST_CASE("Problem 537 -- [-2,null, -3], -5 ==> true")
{
    TreeNode<> *input_1 = new TreeNode<>(-2,
                                               nullptr,
                                               new TreeNode<>(-3));
    int input_2 = -5;
    bool expected = true;
    CHECK(expected == hasPathSum(input_1, input_2));
}
