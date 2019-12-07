import unittest
from typing import List
from utility.tree_node import TreeNode


class Solution:
    # Recursive solution
    def postorderTraversal_recursion(self, root: TreeNode) -> List[int]:
        result = []

        if root is not None:
            if root.left is not None:
                left = self.postorderTraversal_recursion(root.left)
                result = result + left
            if root.right is not None:
                right = self.postorderTraversal_recursion(root.right)
                result = result + right
            result.append(root.val)
        return result

    # Recursive solution
    def postorderTraversal_iterative(self, root: TreeNode) -> List[int]:
        result: List[int] = []
        if root is not None:
            iteration: List[(TreeNode, int)] = []
            iteration.append((root, 0))
            while(len(iteration) != 0):
                current_tuple: (TreeNode, int) = iteration.pop()
                if current_tuple[1] == 0:
                    iteration.append((current_tuple[0], 1))
                    if current_tuple[0].left is not None:
                        iteration.append((current_tuple[0].left, 0))
                elif current_tuple[1] == 1:
                    iteration.append((current_tuple[0], 2))
                    if current_tuple[0].right is not None:
                        iteration.append((current_tuple[0].right, 0))
                else:
                    result.append(current_tuple[0].val)
        return result


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test(self):
        root = TreeNode(1,
                        None,
                        TreeNode(
                            2,
                            TreeNode(
                                3,
                                None,
                                None
                            ),
                            None
                        ))
        s = Solution()
        self.assertTrue([3, 2, 1] == s.postorderTraversal_recursion(root))
        self.assertTrue([3, 2, 1] == s.postorderTraversal_iterative(root))


if __name__ == '__main__':
    unittest.main()
