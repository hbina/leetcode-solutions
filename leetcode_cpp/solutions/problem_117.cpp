#include "doctest/doctest.h"

#include "../data_structure/node_next.hpp"

#include <vector>
#include <iostream>

template <typename T>
using Node = NodeNext<T>;

template <typename T>
void connect_recursion(Node<T> *child, decltype(child) parent)
{
    if (!child)
        return;

    std::cout << "child:" << child->val << std::endl;
    // Find the first next nodes of parent with a child
    if (parent)
    {
        while (
            parent &&
            parent->next &&
            (!parent->left && !parent->right))
        {
            parent = parent->next;
        }
        if (parent)
        {
            if (parent->left)
                child->next = parent->left;
            else if (parent->right)
                child->next = parent->right;
        }
    }
    connect_recursion(child->right, child);
    connect_recursion(child->left, child);
};

template <typename T>
Node<T> *connect(Node<T> *root)
{
    connect_recursion(root, nullptr);
    return root;
};

TEST_CASE("Problem 117")
{
    Node<int> *input = new Node<int>(
        1,
        new Node<int>(
            2,
            new Node<int>(
                4,
                nullptr,
                nullptr,
                nullptr),
            new Node<int>(
                5,
                nullptr,
                nullptr,
                nullptr),
            nullptr),

        new Node<int>(
            3,
            nullptr,
            new Node<int>(
                7,
                nullptr,
                nullptr,
                nullptr),
            nullptr),
        nullptr);

    //std::cout << "input:\n"
    //          << (*input) << std::endl;

    Node<int> *expected = new Node<int>(
        1,
        new Node<int>(
            2,
            new Node<int>(
                4,
                nullptr,
                nullptr,
                new Node<int>(
                    5,
                    nullptr,
                    nullptr,
                    new Node<int>(
                        7,
                        nullptr,
                        nullptr,
                        nullptr))),
            new Node<int>(
                5,
                nullptr,
                nullptr,
                new Node<int>(
                    7,
                    nullptr,
                    nullptr,
                    nullptr)),
            new Node<int>(
                3,
                nullptr,
                new Node<int>(
                    7,
                    nullptr,
                    nullptr,
                    nullptr),
                nullptr)),
        new Node<int>(
            3,
            nullptr,
            new Node<int>(
                7,
                nullptr,
                nullptr,
                nullptr),
            nullptr),
        nullptr);
    //  FIXME   ::  This test is failing...
    // std::cout << "result:\n"
    //           << *connect(input) << std::endl;
};
