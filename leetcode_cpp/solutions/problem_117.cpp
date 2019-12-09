#include "doctest/doctest.h"

#include "../data_structure/node_next.hpp"

#include <vector>

using Node = NodeNext;

void connect_recursion(Node *root, Node *current_next)
{
    root->next = current_next;

    // Find the next node for the child
    Node *leftmost_next_node = nullptr;

    // Find the first next nodes of root with a child
    while (
        // Parent have a next value
        current_next &&
        // Parent does not have any child
        (!current_next->left || !current_next->right))
    {
        current_next = current_next->next;
    }

    // If the previous next yield any next nodes with a child,
    // then assign next node with that node's left if possible
    if (current_next)
    {
        if (current_next->left)
        {
            leftmost_next_node = current_next->left;
        }
        else
        {
            leftmost_next_node = current_next->right;
        }
    }

    if (root->right)
        connect_recursion(root->right, leftmost_next_node);
    if (root->left)
        connect_recursion(root->left, root->right);
}

Node *connect(Node *root)
{
    connect_recursion(root, nullptr);
    return root;
}

TEST_CASE("Problem 117")
{
    Node *root = new Node(
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
    CHECK(expected == connect(root));
};
