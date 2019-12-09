from utility.tree_node import TreeNode
from typing import List
import unittest


# There are 2 intuitions to this problem:
#   1.  Every nodes above the LCA are also their ancestors.
#   2.  Traversing from the root -> down, the node that reports both of its child is the LCA.
#       Assuming that we stop when this is true.

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        p_path = getPathTo(root, p)
        q_path = getPathTo(root, q)
        latest = root
        for x in zip(p_path, q_path):
            if x[0].val != x[1].val:
                return latest
            else:
                latest = x[0]
        return latest


def getPathTo(root: TreeNode, p_tree: TreeNode):
    result = []
    if root.val == p_tree.val:
        result.append(root)
        return result
    elif root.left is None and root.right is None:
        return result
    else:
        if root.left is not None:
            tmp = getPathTo(root.left, p_tree)
            if len(tmp) != 0:
                result.append(root)
                return result + tmp
        if root.right is not None:
            tmp = getPathTo(root.right, p_tree)
            if len(tmp) != 0:
                result.append(root)
                return result + tmp
        return result


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test(self):
        s = Solution()
        p = TreeNode(5,
                     TreeNode(6),
                     TreeNode(2,
                              TreeNode(7),
                              TreeNode(4)))
        q = TreeNode(1,
                     TreeNode(0),
                     TreeNode(8))
        tree = TreeNode(3,
                        p,
                        q)
        self.assertTrue(s.lowestCommonAncestor(tree, p, q).val == tree.val)
