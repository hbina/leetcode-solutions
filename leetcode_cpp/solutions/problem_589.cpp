#include "doctest/doctest.h"

#include "../data_structure/node.hpp"

#include <vector>
#include <stack>
#include <iostream>

template <typename T>
constexpr std::vector<T> preorder_iterative(Node<T> *root)
{
    std::vector<T> result = {};
    std::deque<Node<T> *> s = {nullptr};
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
std::vector<T> preorder_recursive(Node<T> *root)
{
    std::vector<T> result = {};
    if (root)
    {
        result.push_back(root->val);
        for (Node<T> *child : root->children)
        {
            std::vector<int> tmp = preorder_recursive(child);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
    }
    return result;
}

TEST_CASE("problem 589 -- iterative")
{
    Node<int> *input = new Node<int>(1,
                                     {new Node<int>(3,
                                                    {new Node<int>(5),
                                                     new Node<int>(6)}),
                                      new Node<int>(2),
                                      new Node<int>(4)});
    std::vector<int> expected = {1, 3, 5, 6, 2, 4};
    CHECK(expected == preorder_iterative(input));
}

TEST_CASE("problem 589 -- recursive")
{
    Node<int> *input = new Node<int>(1,
                                     {new Node<int>(3,
                                                    {new Node<int>(5),
                                                     new Node<int>(6)}),
                                      new Node<int>(2),
                                      new Node<int>(4)});
    std::vector<int> expected = {1, 3, 5, 6, 2, 4};
    std::vector<int> result = preorder_recursive(input);
    CHECK(expected == result);
}
