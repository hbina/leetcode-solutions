#pragma once

#include <iostream>

template <typename T = int>
struct TreeNode
{
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  constexpr TreeNode() = delete;

  constexpr TreeNode(const T &x)
      : val(x),
        left(nullptr),
        right(nullptr) {}

  constexpr TreeNode(const T &val,
                     TreeNode *left,
                     TreeNode *right)
      : val(val),
        left(left),
        right(right) {}

  ~TreeNode()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }

  template <typename T2>
  friend std::ostream &operator<<(std::ostream &os, const TreeNode<T2> &rhs);
  template <typename T2>
  constexpr friend bool operator==(const TreeNode<T2> &lhs, const TreeNode<T2> &rhs);
};

template <typename T>
constexpr bool operator==(const TreeNode<T> &lhs, const TreeNode<T> &rhs)
{
  bool value_equal = (lhs.val == rhs.val);
  bool left_equal = false;
  if (lhs.left && rhs.left)
  {
    left_equal = (*lhs.left == *rhs.left);
  }
  else if (!lhs.left && !rhs.left)
  {
    left_equal = true;
  }
  bool right_equal = false;
  if (lhs.right && rhs.right)
  {
    right_equal = (*lhs.right == *rhs.right);
  }
  else if (!lhs.right && !rhs.right)
  {
    right_equal = true;
  }
  return value_equal && left_equal && right_equal;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TreeNode<T> &rhs)
{
  os << " " << rhs.val;
  if (rhs.left)
  {
    os << " " << *rhs.left;
  }
  if (rhs.right)
  {
    os << " " << *rhs.right;
  }
  return os;
}
