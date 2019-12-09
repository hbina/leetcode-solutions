#pragma once

#include <vector>

// Use template and std::array
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

  ~Node()
  {
    for (Node *x : children)
    {
      delete x;
    }
  }
};