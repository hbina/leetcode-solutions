#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

#include <vector>
#include <stack>

template <typename T>
std::vector<std::vector<T>> levelOrderBottom(const TreeNode<T> *root)
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

TEST_CASE("problem_107")
{
    const TreeNode<> *input =
        new TreeNode<>(3,
                       new TreeNode<>(9),
                       new TreeNode<>(20,
                                      new TreeNode<>(15),
                                      new TreeNode<>(7)));
    const std::vector<std::vector<int>> expected = {
        {3},
        {9, 20},
        {15, 7}};
    CHECK(expected == levelOrderBottom(input));
    delete input;
}
