#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *tmp_left = root->left;
    TreeNode *tmp_right = root->right;
    root->left = invertTree(tmp_right);
    root->right = invertTree(tmp_left);
    return root;
}