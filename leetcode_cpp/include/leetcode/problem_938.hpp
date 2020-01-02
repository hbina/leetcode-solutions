#pragma once

#include "data_structure/tree_node.hpp"

namespace leetcode
{

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

}; // namespace leetcode
