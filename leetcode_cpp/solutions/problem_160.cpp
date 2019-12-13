#include "doctest/doctest.h"

#include "../data_structure/list_node.hpp"

#include <iostream>

template <typename T>
constexpr ListNode<T> *getIntersectionNode(ListNode<T> *headA, ListNode<T> *headB)
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

TEST_CASE("Problem 160")
{
    ListNode<int> *c1 = new ListNode<int>(
        6,
        new ListNode<int>(
            7,
            new ListNode<int>(
                8,
                nullptr)));
    ListNode<int> *a1 = new ListNode<int>(
        1,
        new ListNode<int>(
            2,
            c1));
    ListNode<int> *b1 = new ListNode<int>(
        3,
        new ListNode<int>(
            4,
            new ListNode<int>(
                5,
                c1)));
    CHECK(*c1 == *getIntersectionNode(a1, b1));
}
