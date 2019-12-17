#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
std::size_t maxDepth(const TreeNode<T> *root)
{
    if (!root)
    {
        return 0;
    }
    std::size_t left = 1 + maxDepth(root->left);
    std::size_t right = 1 + maxDepth(root->right);
    return left > right ? left : right;
}

TEST_CASE("Problem 535")
{
    const TreeNode<> input = TreeNode<>(
        3,
        new TreeNode<>(9),
        new TreeNode<>(20,
                       new TreeNode<>(15),
                       new TreeNode<>(7)));
    int expected = 3;
    CHECK(expected == maxDepth(&input));
}

TEST_CASE("Problem 535")
{
    const TreeNode<> input = TreeNode<>(3);
    int expected = 1;
    CHECK(expected == maxDepth(&input));
}

TEST_CASE("Problem 535")
{
    TreeNode<> *input = nullptr;
    int expected = 0;
    CHECK(expected == maxDepth(input));
}

TEST_CASE("Problem 535")
{
    const TreeNode<> input =
        TreeNode<>(3,
                   nullptr,
                   new TreeNode<>(20,
                                  nullptr,
                                  new TreeNode<>(7,
                                                 nullptr,
                                                 new TreeNode<>(7))));
    const int expected = 4;
    CHECK(expected == maxDepth(&input));
}
