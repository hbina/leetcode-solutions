#pragma once

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr) {}

  TreeNode(TreeNode *left,
           TreeNode *right,
           int val)
      : left(left),
        right(right),
        val(val) {}
};
