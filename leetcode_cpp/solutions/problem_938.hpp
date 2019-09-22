#pragma once

#include "../data_structure/tree_node.hpp"

namespace Solution
{
int rangeSumBST(TreeNode *root, int L, int R)
{
    if (root == nullptr)
    {
        return 0;
    }
    else if (root->val < L)
    {
        return rangeSumBST(root->right, L, R);
    }
    else if (root->val > R)
    {
        return rangeSumBST(root->left, L, R);
    }
    else
    {
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}
}; // namespace Solution