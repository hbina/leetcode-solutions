#include "../data_structure/tree_node.hpp"

namespace leetcode
{

template <typename T>
static constexpr void
bstToGst_Recursive(TreeNode<T> *root, T &accumulator)
{
    if (root->right)
        bstToGst_Recursive(root->right, accumulator);
    accumulator += root->val;
    root->val = accumulator;
    if (root->left)
        bstToGst_Recursive(root->left, accumulator);
}

template <typename T>
static constexpr TreeNode<T> *
bstToGst(TreeNode<T> *root)
{
    T init = 0;
    bstToGst_Recursive(root, init);
    return root;
}

} // namespace leetcode
