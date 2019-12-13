#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
constexpr bool isUnivalTree(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool left_same = true;
    bool right_same = true;

    if (root->left != nullptr)
    {
        left_same =
            (root->val == root->left->val) &
            isUnivalTree(root->left);
        if (!left_same)
        {
            return false;
        }
    }
    
    if (root->right != nullptr)
    {
        right_same =
            (root->val == root->right->val) &
            isUnivalTree(root->right);
        if (!right_same)
        {
            return false;
        }
    }
    return left_same & right_same;
}
