#pragma once

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x)
      : val(x),
        next(nullptr) {}

  ~ListNode()
  {
    delete next;
  }
};
