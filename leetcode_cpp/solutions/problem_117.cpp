#include "doctest/doctest.h"

#include "../data_structure/node_next.hpp"

#include <vector>
#include <iostream>

template <typename T>
static constexpr NodeNext<T> *connect(NodeNext<T> *root)
{
    if (!root)
        return nullptr;

    NodeNext<T> *nextmost = root->next;
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

TEST_CASE("problem_117")
{
    NodeNext<> *input =
        new NodeNext<>(1,
                       new NodeNext<>(2,
                                      new NodeNext<>(4,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      new NodeNext<>(5,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      nullptr),

                       new NodeNext<>(3,
                                      nullptr,
                                      new NodeNext<>(7,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      nullptr),
                       nullptr);
    NodeNext<> *expected_node_7 = new NodeNext<>(7);
    NodeNext<> *expected_node_5 =
        new NodeNext<>(5,
                       nullptr,
                       nullptr,
                       expected_node_7);
    NodeNext<> *expected_node_4 =
        new NodeNext<>(4,
                       nullptr,
                       nullptr,
                       expected_node_5);
    NodeNext<> *expected_node_3 =
        new NodeNext<>(3,
                       nullptr,
                       expected_node_7,
                       nullptr);
    NodeNext<> *expected_node_2 =
        new NodeNext<>(2,
                       expected_node_4,
                       expected_node_5,
                       expected_node_3);
    const NodeNext<> *expected =
        new NodeNext<>(1,
                       expected_node_2,
                       expected_node_3,
                       nullptr);
    connect(input);
    CHECK(*expected == *input);
    delete input;
    delete expected;
}
