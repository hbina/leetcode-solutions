#pragma once

#include <iostream>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(const int &x)
      : val(x),
        left(nullptr),
        right(nullptr) {}

  TreeNode(const int &val,
           TreeNode *left,
           TreeNode *right)
      : val(val),
        left(left),
        right(right) {}

  ~TreeNode()
  {
    delete left;
    delete right;
  }

  friend bool operator==(const TreeNode &lhs, const TreeNode &rhs);
  friend std::ostream &operator<<(std::ostream &os, const TreeNode &rhs);
};
