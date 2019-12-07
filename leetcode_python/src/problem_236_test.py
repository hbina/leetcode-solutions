from src.utility.tree_node import TreeNode
from typing import List
import unittest


# There are 2 intuitions to this problem:
#   1.  Every nodes above the LCA are also their ancestors.
#   2.  Traversing from the root -> down, the node that reports both of its child is the LCA.
#       Assuming that we stop when this is true.

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        p_path = root.getPathTo(p)
        q_path = root.getPathTo(q)
        latest = root
        for x in zip(p_path, q_path):
            if x[0].val != x[1].val:
                return latest
            else:
                latest = x[0]
        return latest


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test_problem_236(self):
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
