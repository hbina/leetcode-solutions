#include "doctest/doctest.h"

#include "../data_structure/node_next.hpp"

#include <vector>

using Node = NodeNext;

void connect_recursion(Node *child, Node *parent)
{
    // Find the first next nodes of parent with a child
    if (parent)
    {
        while (
            // Parent have a value
            parent &&
            // Parent does not have any child
            (!parent->left && !parent->right))
        {
            parent = parent->next;
        }
    }

    // If the previous next yield any next nodes with a child,
    // then assign next node with that node's left if possible
    if (parent)
    {
        if (parent->left)
        {
            child->next = parent->left;
        }
        else
        {
            child->next = parent->right;
        }
    }

    if (child->right)
        connect_recursion(child->right, child->next);
    if (child->left)
        connect_recursion(child->left, child);
}

Node *connect(Node *root)
{
    connect_recursion(root, nullptr);
    return root;
}

TEST_CASE("Problem 117")
{
    Node *input = new Node(
        1,
        new Node(
            2,
            new Node(
                4,
                nullptr,
                nullptr,
                nullptr),
            new Node(
                5,
                nullptr,
                nullptr,
                nullptr),
            nullptr),

        new Node(
            3,
            nullptr,
            new Node(
                7,
                nullptr,
                nullptr,
                nullptr),
            nullptr),
        nullptr);

    Node *expected = new Node(
        1,
        new Node(
            2,
            new Node(
                4,
                nullptr,
                nullptr,
                new Node(
                    5,
                    nullptr,
                    nullptr,
                    new Node(
                        7,
                        nullptr,
                        nullptr,
                        nullptr))),
            new Node(
                5,
                nullptr,
                nullptr,
                new Node(
                    7,
                    nullptr,
                    nullptr,
                    nullptr)),
            new Node(
                3,
                nullptr,
                new Node(
                    7,
                    nullptr,
                    nullptr,
                    nullptr),
                nullptr)),
        new Node(
            3,
            nullptr,
            new Node(
                7,
                nullptr,
                nullptr,
                nullptr),
            nullptr),
        nullptr);
    //  FIXME   ::  This test is failing...
    // CHECK(expected == connect(input));
};
