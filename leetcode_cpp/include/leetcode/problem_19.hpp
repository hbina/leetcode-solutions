#pragma once

#include "data_structure/list_node.hpp"

namespace leetcode
{

template <
    typename Type,
    typename IndexType = int>
static constexpr ListNode<Type> *
removeNthFromEnd(ListNode<Type> *head, const IndexType &n)
{
    ListNode<Type> *barrier = head;
    for (IndexType iter = 0; iter < n; iter++)
    {
        barrier = barrier->next;
    }

    if (!barrier)
    {
        ListNode<Type> *result = head->next;
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        ListNode<Type> *iter = head;
        while (barrier->next)
        {
            barrier = barrier->next;
            iter = iter->next;
        }

        ListNode<Type> *tmp = iter->next;
        iter->next = iter->next->next;
        tmp->next = nullptr;
        delete tmp;

        return head;
    }
}

} // namespace leetcode
