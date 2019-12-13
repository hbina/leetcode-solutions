#include "doctest/doctest.h"

#include "../data_structure/node_next.hpp"

#include <vector>
#include <iostream>

template <typename T>
using Node = NodeNext<T>;

template <typename T>
Node<T> *connect(Node<T> *root)
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
    CHECK(*expected == *connect(input));
};
