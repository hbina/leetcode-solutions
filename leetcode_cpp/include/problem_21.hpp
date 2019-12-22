#include "../data_structure/list_node.hpp"

namespace leetcode
{

// Can be generalized further
template <typename T>
static constexpr std::tuple<
    ListNode<T> *,
    ListNode<T> *,
    ListNode<T> *>
advanceZip(ListNode<T> *lhs, ListNode<T> *rhs)
{
    if (lhs && rhs)
    {
        if (lhs->val < rhs->val)
        {
            return {lhs, lhs->next, rhs};
        }
        else
        {
            return {rhs, lhs, rhs->next};
        }
    }
    else if (lhs)
    {
        return {lhs, lhs->next, nullptr};
    }
    else if (rhs)
    {
        return {rhs, nullptr, rhs->next};
    }
    else
    {
        return {nullptr, nullptr, nullptr};
    }
}

template <typename T>
static constexpr ListNode<T> *
mergeTwoLists(ListNode<T> *lhs, ListNode<T> *rhs)
{
    if (lhs && rhs)
    {
        auto [root, lhs_iter, rhs_iter] = advanceZip(lhs, rhs);
        ListNode<T> *iter = root;
        while (lhs_iter || rhs_iter)
        {
            auto [iter_next, lhs_next, rhs_next] = advanceZip(lhs_iter, rhs_iter);
            iter->next = iter_next;
            iter = iter->next;
            lhs_iter = lhs_next;
            rhs_iter = rhs_next;
        }
        return root;
    }
    else if (lhs)
    {
        return lhs;
    }
    else if (rhs)
    {
        return rhs;
    }
    else
    {
        return nullptr;
    }
}

}; // namespace leetcode
