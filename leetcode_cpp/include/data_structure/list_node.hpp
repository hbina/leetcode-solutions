#pragma once

#include <string>
#include <iostream>

template <typename T = int>
struct ListNode
{
  T val;
  ListNode *next;
  constexpr ListNode(const T &x)
      : val(x),
        next(nullptr) {}
  constexpr ListNode(const T &x,
                     ListNode *next)
      : val(x),
        next(next) {}

  ~ListNode()
  {
    if (next)
      delete next;
  }

  template <typename T2>
  friend std::ostream &operator<<(std::ostream &os, const ListNode<T2> &rhs);
  template <typename T2>
  constexpr friend bool operator==(const ListNode<T2> &lhs, const ListNode<T2> &rhs);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const ListNode<T> &rhs)
{
  os << "ListNode val:" << rhs.val;
  return os;
}

template <typename T>
constexpr bool operator==(const ListNode<T> &lhs, const ListNode<T> &rhs)
{
  bool value_equal = (lhs.val == rhs.val);
  if (lhs.next && rhs.next)
  {
    return value_equal && (*lhs.next == *rhs.next);
  }
  else if (!lhs.next && !rhs.next)
  {
    return value_equal;
  }
  else
  {
    return false;
  }
}
