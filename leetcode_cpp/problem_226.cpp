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
};