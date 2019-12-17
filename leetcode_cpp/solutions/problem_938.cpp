#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
static constexpr int rangeSumBST_recursion(
    const TreeNode<T> *root, const T &L, const T &R)
{
    if (root == nullptr)
    {
        return 0;
    }
    else if (root->val < L)
    {
        return rangeSumBST_recursion(root->right, L, R);
    }
    else if (root->val > R)
    {
        return rangeSumBST_recursion(root->left, L, R);
    }
    else
    {
        return root->val + rangeSumBST_recursion(root->left, L, R) + rangeSumBST_recursion(root->right, L, R);
    }
}

TEST_CASE("problem 938")
{
    const TreeNode<> *input =
        new TreeNode<>(10,
                       new TreeNode<>(5,
                                      new TreeNode<>(3),
                                      new TreeNode<>(7)),
                       new TreeNode<>(15,
                                      nullptr,
                                      new TreeNode<>(18)));
    const int expected = 32;
    const int result = rangeSumBST_recursion(input, 7, 15);
    CHECK(expected == result);
    delete input;
}
