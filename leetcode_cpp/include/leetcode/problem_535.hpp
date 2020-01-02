#pragma once

#include "data_structure/tree_node.hpp"

namespace leetcode
{

template <typename T>
std::size_t maxDepth(const TreeNode<T> *root)
{
    if (!root)
    {
        return 0;
    }
    std::size_t left = 1 + maxDepth(root->left);
    std::size_t right = 1 + maxDepth(root->right);
    return left > right ? left : right;
}

}; // namespace leetcode