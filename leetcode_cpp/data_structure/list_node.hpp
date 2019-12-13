#pragma once

#include <string>
#include <iostream>

template <typename T>
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
    delete next;
  }

  template <typename T>
  constexpr friend std::ostream &operator<<(std::ostream &os, const ListNode<T> &rhs);
  template <typename T>
  constexpr friend bool operator==(const ListNode &lhs, const ListNode<T> &rhs);
};

template <typename T>
constexpr std::ostream &operator<<(std::ostream &os, const ListNode<T> &rhs)
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
};
