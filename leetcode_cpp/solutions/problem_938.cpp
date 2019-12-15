#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
constexpr int rangeSumBST_recursion(TreeNode<T> *root, const T &L, const T &R)
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
    TreeNode<> *input =
        new TreeNode<>(10,
                          new TreeNode<>(5,
                                            new TreeNode<>(3),
                                            new TreeNode<>(7)),
                          new TreeNode<>(15,
                                            nullptr,
                                            new TreeNode<>(18)));
    CHECK(32 == rangeSumBST_recursion(input, 7, 15));
}
