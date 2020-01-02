#pragma once

#include <iostream>
template <typename T = int>
class NodeNext
{
public:
  T val;
  NodeNext *left;
  NodeNext *right;
  NodeNext *next;

  constexpr NodeNext() = delete;

  constexpr NodeNext(const T &val)
      : val(val),
        left(nullptr),
        right(nullptr),
        next(nullptr) {}

  constexpr NodeNext(const T &val,
                     NodeNext<T> *left,
                     NodeNext<T> *right,
                     NodeNext<T> *next)
      : val(val),
        left(left),
        right(right),
        next(next) {}

  ~NodeNext()
  {
    delete left;
    delete right;
  }

  template <typename T2>
  friend std::ostream &operator<<(std::ostream &os, const NodeNext<T2> &rhs);
  template <typename T2>
  constexpr friend bool operator==(const NodeNext<T2> &lhs, const NodeNext<T2> &rhs);
};

template <typename T>
constexpr bool operator==(const NodeNext<T> &lhs, const NodeNext<T> &rhs)
{
  bool value_equal = lhs.val == rhs.val;
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

  bool next_equal = false;
  if (lhs.next && rhs.next)
  {
    next_equal = (*lhs.next == *rhs.next);
  }
  else if (!lhs.next && !rhs.next)
  {
    next_equal = true;
  }

  return value_equal && left_equal && right_equal && next_equal;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const NodeNext<T> &rhs)
{
  os << rhs.val << " ";
  if (rhs.left)
    os << *rhs.left << " ";
  else
    os << "null ";
  if (rhs.right)
    os << *rhs.right << " ";
  else
    os << "null ";
  if (rhs.next)
    os << *rhs.next << " ";
  else
    os << "null ";
  return os;
}
