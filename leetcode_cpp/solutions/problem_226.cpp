#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

#include <memory>

template <typename T>
static constexpr TreeNode<T> *invertTree(TreeNode<T> *root)
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
    const TreeNode<> *result = invertTree(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}
