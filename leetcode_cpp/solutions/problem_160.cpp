#include "doctest/doctest.h"

#include "../data_structure/list_node.hpp"

#include <iostream>

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
    {
        return nullptr;
    }
    ListNode *pointerA = headA;
    ListNode *pointerB = headB;

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
    ListNode *c1 = new ListNode(
        6,
        new ListNode(
            7,
            new ListNode(
                8,
                nullptr)));
    ListNode *a1 = new ListNode(
        1,
        new ListNode(
            2,
            c1));
    ListNode *b1 = new ListNode(
        3,
        new ListNode(
            4,
            new ListNode(
                5,
                c1)));
    CHECK(c1 == getIntersectionNode(a1, b1));
};