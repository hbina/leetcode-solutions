#pragma once

#include "../data_structure/tree_node.hpp"

namespace Solution
{
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root->val == val)
    {
        return root;
    }
    else
    {
        TreeNode *left = nullptr, *right = nullptr;

        // Begin search on left branch if it exists
        if (root->left != nullptr)
        {
            left = searchBST(root->left, val);
        }
        // Begin search on right branch if it exists and left branch failed...
        if (root->right != nullptr && left == nullptr)
        {
            right = searchBST(root->right, val);
        }

        // If left failed, then the only option is right.
        // Right could be nullptr, but that's perfectly fine.
        if (left == nullptr)
        {
            return right;
        }
        else
        {
            return left;
        }
    }
}

TreeNode *searchBST_2(TreeNode *root, int val)
{
    TreeNode *tree = root;
    while (tree)
    {
        if (tree->val == val) // found the solution
            return tree;
        else if (tree->val < val) // current is smaller, then go right
            tree = tree->right;
        else // current is larger, then go left
            tree = tree->left;
    }
    return nullptr;
}
}; // namespace Solution