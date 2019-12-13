#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
constexpr TreeNode<T> *invertTree(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        TreeNode<T> *tmp_left = root->left;
        TreeNode<T> *tmp_right = root->right;
        root->left = invertTree(tmp_right);
        root->right = invertTree(tmp_left);
        return root;
    }
}

TEST_CASE("problem_226")
{
    TreeNode<int> *input = new TreeNode<int>(
        4,
        new TreeNode<int>(
            2,
            new TreeNode<int>(1),
            new TreeNode<int>(3)),
        new TreeNode<int>(7,
                          new TreeNode<int>(6),
                          new TreeNode<int>(9)));

    TreeNode<int> *expected = new TreeNode<int>(
        4,
        new TreeNode<int>(
            7,
            new TreeNode<int>(9),
            new TreeNode<int>(6)),
        new TreeNode<int>(2,
                          new TreeNode<int>(3),
                          new TreeNode<int>(1)));

    CHECK(*expected == *invertTree(input));
}
