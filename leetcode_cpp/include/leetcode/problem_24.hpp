#pragma once

#include "data_structure/list_node.hpp"

namespace leetcode
{

template <typename T>
ListNode<T> *swapPairs(ListNode<T> *head)
{
    if (!head)
    {
        return nullptr;
    }
    else if (!head->next)
    {
        return head;
    }
    else
    {
        ListNode<T> *result = head->next;
        head->next = swapPairs(result->next);
        result->next = head;
        return result;
    }
}

} // namespace leetcode
