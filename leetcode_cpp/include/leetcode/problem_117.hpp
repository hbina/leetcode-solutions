#pragma once

#include "data_structure/node_next.hpp"

#include <vector>
#include <iostream>

namespace leetcode
{

template <typename T>
static constexpr NodeNext<T> *
connect(NodeNext<T> *root)
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

} // namespace leetcode
