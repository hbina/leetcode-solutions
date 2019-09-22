#pragma once

#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() = delete;

    Node(int p_val,
         std::vector<Node *> p_children)
        : val(p_val),
          children(p_children) {}
};