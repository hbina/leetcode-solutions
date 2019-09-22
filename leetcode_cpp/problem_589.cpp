#include "data_structure/node.hpp"

#include <vector>
#include <stack>
#include <iostream>

namespace Solution
{
std::vector<int> preorder(Node *root)
{
    std::vector<int> result;
    std::deque<Node *> s{nullptr};
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
}; // namespace Solution
