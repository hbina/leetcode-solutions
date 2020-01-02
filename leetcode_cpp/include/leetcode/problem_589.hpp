#include "../data_structure/node.hpp"

#include <vector>
#include <stack>
#include <iostream>

namespace leetcode
{

template <typename T>
static constexpr std::vector<T> preorder_iterative(const Node<T> *root)
{
    std::vector<T> result = {};
    std::deque<const Node<T> *> s = {nullptr};

    while (root)
    {
        result.push_back(root->val);
        for (auto iter = root->children.rbegin(); iter != root->children.rend(); ++iter)
        {
            s.push_front(*iter);
        }
        root = s.front();
        s.pop_front();
    }
    return result;
}

template <typename T>
std::vector<T> preorder_recursive(const Node<T> *root)
{
    std::vector<T> result = {};
    if (root)
    {
        result.push_back(root->val);
        for (const Node<T> *child : root->children)
        {
            std::vector<int> tmp = preorder_recursive(child);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
    }
    return result;
}

}; // namespace leetcode
