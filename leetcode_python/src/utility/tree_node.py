# How to import : from src.utility.tree_node import TreeNode


class TreeNode:
    def __init__(self, x, p_left=None, p_right=None):
        self.val = x
        self.left = p_left
        self.right = p_right

    def __repr__(self):
        return 'TreeNode({})'.format(self.val)

    def __str__(self):
        return 'TreeNode({})'.format(self.val)


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
