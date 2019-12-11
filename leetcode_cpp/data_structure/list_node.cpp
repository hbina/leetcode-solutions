#include "list_node.hpp"

std::ostream &operator<<(std::ostream &os, const ListNode &rhs)
{
    os << "ListNode val:" << rhs.val;
    return os;
}

bool operator==(const ListNode &lhs, const ListNode &rhs)
{
    bool value_equal = (lhs.val == rhs.val);
    if (lhs.next && rhs.next)
    {
        return value_equal && (*lhs.next == *rhs.next);
    }
    else if (!lhs.next && !rhs.next)
    {
        return value_equal;
    }
    else
    {
        return false;
    }
};