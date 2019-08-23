#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> preorder(Node *root)
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
};