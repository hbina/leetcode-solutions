#pragma once

#include "data_structure/list_node.hpp"

#include <iostream>

namespace leetcode
{

template <typename T>
static constexpr ListNode<T> *getIntersectionNode(ListNode<T> *headA, ListNode<T> *headB)
{
    if (!headA || !headB)
    {
        return nullptr;
    }
    ListNode<T> *pointerA = headA;
    ListNode<T> *pointerB = headB;

    // Recalibrate pointers
    int both_reverted = 2;
    while (both_reverted != 0)
    {
        if (pointerA->next)
        {
            pointerA = pointerA->next;
        }
        else
        {
            pointerA = headB;
            both_reverted -= 1;
        }

        if (pointerB->next)
        {
            pointerB = pointerB->next;
        }
        else
        {
            pointerB = headA;
            both_reverted -= 1;
        }
    }
    while (pointerA)
    {
        if (pointerA == pointerB)
        {
            return pointerA;
        }
        else
        {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        }
    }
    return nullptr;
}

}; // namespace leetcode
