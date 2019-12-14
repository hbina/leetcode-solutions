#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
T maxDepth(TreeNode<T> *root)
{
    if (!root)
    {
        return 0;
    }
    T left = 1 + maxDepth(root->left);
    T right = 1 + maxDepth(root->right);
    return left > right ? left : right;
}

TEST_CASE("Problem 535")
{
    TreeNode<int> *input = new TreeNode<int>(3,
                                             new TreeNode<int>(9),
                                             new TreeNode<int>(20,
                                                               new TreeNode<int>(15),
                                                               new TreeNode<int>(7)));
    int expected = 3;
    CHECK(expected == maxDepth(input));
}

TEST_CASE("Problem 535")
{
    TreeNode<int> *input = new TreeNode<int>(3);
    int expected = 1;
    CHECK(expected == maxDepth(input));
}

TEST_CASE("Problem 535")
{
    TreeNode<int> *input = nullptr;
    int expected = 0;
    CHECK(expected == maxDepth(input));
}

TEST_CASE("Problem 535")
{
    TreeNode<int> *input = new TreeNode<int>(3,
                                             nullptr,
                                             new TreeNode<int>(20,
                                                               nullptr,
                                                               new TreeNode<int>(7,
                                                                                 nullptr,
                                                                                 new TreeNode<int>(7))));
    int expected = 4;
    CHECK(expected == maxDepth(input));
}
