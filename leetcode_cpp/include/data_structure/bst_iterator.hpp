#pragma once

#include "tree_node.hpp"

#include <stack>
#include <optional>

namespace leetcode
{

template <typename T>
class BSTIterator
{
private:
    std::stack<const TreeNode<T> *> stack;

    constexpr void
    parse_node(const TreeNode<T> *input)
    {
        while (input)
        {
            stack.push(input);
            input = input->left;
        }
    }

public:
    constexpr BSTIterator(const TreeNode<T> *root)
    {
        parse_node(root);
    }

    constexpr const TreeNode<T> *next()
    {
        const TreeNode<T> *result = stack.top();
        stack.pop();
        parse_node(result->right);
        return result;
    }

    constexpr const TreeNode<T> *peek() const
    {
        return stack.top();
    }

    constexpr bool hasNext() const
    {
        return !stack.empty();
    }
};

} // namespace leetcode
