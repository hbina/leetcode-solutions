#include "tree_node.hpp"

bool operator==(const TreeNode &lhs, const TreeNode &rhs)
{
    bool value_equal = (lhs.val == rhs.val);
    bool left_equal = false;
    if (lhs.left && rhs.left)
    {
        left_equal = (*lhs.left == *rhs.left);
    }
    else if (!lhs.left && !rhs.left)
    {
        left_equal = true;
    }
    bool right_equal = false;
    if (lhs.right && rhs.right)
    {
        right_equal = (*lhs.right == *rhs.right);
    }
    else if (!lhs.right && !rhs.right)
    {
        right_equal = true;
    }
    return value_equal && left_equal && right_equal;
};

std::ostream &operator<<(std::ostream &os, const TreeNode &rhs)
{
    os << " " << rhs.val;
    if (rhs.left)
    {
        os << " " << *rhs.left;
    }
    if (rhs.right)
    {
        os << " " << *rhs.right;
    }
    return os;
}
