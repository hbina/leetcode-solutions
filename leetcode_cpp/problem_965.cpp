struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
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
};