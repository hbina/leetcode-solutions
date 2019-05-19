#include <cstddef>

#include "data_structure/tree_node.h"

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root->val == val)
        {
            return root;
        }
        else
        {
            TreeNode *left = NULL, *right = NULL;

            // Begin search on left branch if it exists
            if (root->left != NULL)
            {
                left = searchBST(root->left, val);
            }
            // Begin search on right branch if it exists and left branch failed...
            if (root->right != NULL && left == NULL)
            {
                right = searchBST(root->right, val);
            }

            // If left failed, then the only option is right.
            // Right could be null, but that's perfectly fine.
            if (left == NULL)
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
};