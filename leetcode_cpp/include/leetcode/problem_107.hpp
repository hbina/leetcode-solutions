#pragma once

#include "data_structure/tree_node.hpp"

#include <vector>
#include <stack>

namespace leetcode
{

template <typename T>
static constexpr std::vector<std::vector<T>>
levelOrderBottom(const TreeNode<T> *root)
{
    std::vector<std::vector<T>> result = {};
    std::vector<const TreeNode<T> *> layers = {root};
    while (!layers.empty())
    {
        std::vector<T> tmp;
        std::vector<const TreeNode<T> *> next_layers;
        for (const TreeNode<T> *x : layers)
        {
            tmp.push_back(x->val);
            if (x->left)
                next_layers.push_back(x->left);
            if (x->right)
                next_layers.push_back(x->right);
        }
        result.push_back(tmp);
        layers = next_layers;
    }
    return result;
}

} // namespace leetcode
