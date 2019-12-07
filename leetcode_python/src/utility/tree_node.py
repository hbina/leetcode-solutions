# How to import : from src.utility.tree_node import TreeNode

class TreeNode:
    def __init__(self, x, p_left=None, p_right=None):
        self.val = x
        self.left = p_left
        self.right = p_right

    # Convert this into a free function that accepts a TreeNode
    def getPathTo(self, p_tree):
        result = []
        if self.val == p_tree.val:
            result.append(self)
            return result
        elif self.left is None and self.right is None:
            return result
        else:
            if self.left is not None:
                tmp = self.left.getPathTo(p_tree)
                if len(tmp) != 0:
                    result.append(self)
                    return result + tmp
            if self.right is not None:
                tmp = self.right.getPathTo(p_tree)
                if len(tmp) != 0:
                    result.append(self)
                    return result + tmp
            return result

    def __repr__(self):
        return 'TreeNode({})'.format(self.val)

    def __str__(self):
        return 'TreeNode({})'.format(self.val)
