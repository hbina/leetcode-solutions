#include "doctest/doctest.h"

#include "../data_structure/node_next.hpp"

#include <vector>
#include <iostream>

template <typename T = int>
using Node = NodeNext<T>;

template <typename T>
static constexpr Node<T> *connect(Node<T> *root)
{
    if (!root)
        return nullptr;

    Node<T> *nextmost = root->next;
    while (
        nextmost &&
        (!nextmost->left && !nextmost->right) &&
        nextmost->next)
    {
        nextmost = nextmost->next;
    }

    if (root->right)
    {
        if (nextmost)
        {
            if (nextmost->left)
            {
                root->right->next = nextmost->left;
            }
            else
            {
                root->right->next = nextmost->right;
            }
        }
        else
        {
            root->right->next = nullptr;
        }
        connect(root->right);
    }

    if (root->left)
    {
        if (root->right)
        {
            root->left->next = root->right;
            connect(root->left);
        }
        else
        {
            if (nextmost)
            {
                if (nextmost->left)
                {
                    root->left->next = nextmost->left;
                }
                else
                {
                    root->left->next = nextmost->right;
                }
            }
            else
            {
                root->left->next = nullptr;
            }
            connect(root->left);
        }
    }
    return root;
}

TEST_CASE("Problem 117")
{
    Node<> *input = new Node<>(
        1,
        new Node<>(
            2,
            new Node<>(
                4,
                nullptr,
                nullptr,
                nullptr),
            new Node<>(
                5,
                nullptr,
                nullptr,
                nullptr),
            nullptr),

        new Node<>(
            3,
            nullptr,
            new Node<>(
                7,
                nullptr,
                nullptr,
                nullptr),
            nullptr),
        nullptr);

    Node<> *expected = new Node<>(
        1,
        new Node<>(
            2,
            new Node<>(
                4,
                nullptr,
                nullptr,
                new Node<>(
                    5,
                    nullptr,
                    nullptr,
                    new Node<>(
                        7,
                        nullptr,
                        nullptr,
                        nullptr))),
            new Node<>(
                5,
                nullptr,
                nullptr,
                new Node<>(
                    7,
                    nullptr,
                    nullptr,
                    nullptr)),
            new Node<>(
                3,
                nullptr,
                new Node<>(
                    7,
                    nullptr,
                    nullptr,
                    nullptr),
                nullptr)),
        new Node<>(
            3,
            nullptr,
            new Node<>(
                7,
                nullptr,
                nullptr,
                nullptr),
            nullptr),
        nullptr);
    CHECK(*expected == *connect(input));
}
