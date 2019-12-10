#pragma once

#include <string>
#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(const int x)
      : val(x),
        next(nullptr) {}
  ListNode(const int x,
           ListNode *next)
      : val(x),
        next(next) {}

  ~ListNode()
  {
    delete next;
  }

  friend std::ostream &operator<<(std::ostream &os, const ListNode &rhs);
};

std::ostream &operator<<(std::ostream &os, const ListNode &rhs)
{
  os << "ListNode val:" << rhs.val;
  return os;
}