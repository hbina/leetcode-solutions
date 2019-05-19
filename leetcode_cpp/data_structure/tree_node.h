#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int);
};

#endif
