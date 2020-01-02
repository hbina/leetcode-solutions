#include "../data_structure/tree_node.hpp"

#include <memory>

namespace leetcode
{

template <typename T>
static constexpr TreeNode<T> *invertTree(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        TreeNode<T> *tmp_left = root->left;
        TreeNode<T> *tmp_right = root->right;
        root->left = invertTree(tmp_right);
        root->right = invertTree(tmp_left);
        return root;
    }
}

}; // namespace leetcode
