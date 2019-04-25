#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
};