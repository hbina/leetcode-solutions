
#include "../data_structure/tree_node.hpp"

namespace leetcode
{

template <typename T>
bool hasPathSum(const TreeNode<T> *root, int sum)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (!root->left && !root->right && sum == root->val)
    {
        return true;
    }
    else
    {
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
}

}; // namespace leetcode
