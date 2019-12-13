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
};

TEST_CASE("problem 938")
{
    TreeNode<int> *input =
        new TreeNode<int>(10,
                          new TreeNode<int>(5,
                                            new TreeNode<int>(3),
                                            new TreeNode<int>(7)),
                          new TreeNode<int>(15,
                                            nullptr,
                                            new TreeNode<int>(18)));
    CHECK(32 == rangeSumBST_recursion(input, 7, 15));
};
