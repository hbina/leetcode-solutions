#pragma once

#include <vector>

// Use template and std::array
template <typename T>
class Node
{
public:
  T val;
  std::vector<Node<T> *> children;

  Node() = delete;

  Node(const T &p_val)
      : val(p_val) {}

  Node(const T &p_val,
       const std::vector<Node<T> *> &p_children)
      : val(p_val),
        children(p_children) {}

  ~Node()
  {
    for (Node<T> *x : children)
    {
      delete x;
    }
  }
};