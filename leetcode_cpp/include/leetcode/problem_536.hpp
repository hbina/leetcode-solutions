#include "../data_structure/tree_node.hpp"

namespace leetcode
{

template <typename T>
bool isMirror(const TreeNode<T> *lhs, const TreeNode<T> *rhs)
{
    if (lhs == nullptr && rhs == nullptr)
        return true;
    if (lhs == nullptr || rhs == nullptr)
        return false;
    return lhs->val == rhs->val &&
           isMirror(lhs->right, rhs->left) &&
           isMirror(lhs->left, rhs->right);
}

template <typename T>
bool isSymmetric(const TreeNode<T> *root)
{
    return isMirror(root, root);
}

}; // namespace leetcode
