#include "doctest/doctest.h"

#include "../data_structure/list_node.hpp"

ListNode *reverseList_iterative(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode *pointer_before = nullptr;
    ListNode *pointer_current = head;
    ListNode *pointer_after = head->next;

    while (pointer_after)
    {
        pointer_current->next = pointer_before;

        // Update pointers
        pointer_before = pointer_current;
        pointer_current = pointer_after;
        pointer_after = pointer_after->next;
    }
    pointer_current->next = pointer_before;
    return pointer_current;
};

ListNode *reverseList_recursive_helper(ListNode *head, ListNode *next)
{
    // Means that we are at the end.
    if (!next)
    {
        return head;
    }
    else
    {
        ListNode *tmp = next->next;
        next->next = head;
        return reverseList_recursive_helper(next, tmp);
    }
};

ListNode *reverseList_recursive(ListNode *head)
{
    if (head)
    {
        ListNode *tmp = head->next;
        head->next = nullptr;
        return reverseList_recursive_helper(head, tmp);
    }
    else
    {
        return nullptr;
    }
};

TEST_CASE("problem 206")
{
    ListNode *input = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                3,
                new ListNode(
                    4,
                    new ListNode(
                        5)))));

    ListNode *expected = new ListNode(
        5,
        new ListNode(
            4,
            new ListNode(
                3,
                new ListNode(
                    2,
                    new ListNode(
                        1)))));

    CHECK(*reverseList_iterative(input) == *expected);
};

TEST_CASE("problem 206")
{
    ListNode *input = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                3,
                new ListNode(
                    4,
                    new ListNode(
                        5)))));

    ListNode *expected = new ListNode(
        5,
        new ListNode(
            4,
            new ListNode(
                3,
                new ListNode(
                    2,
                    new ListNode(
                        1)))));

    CHECK(*reverseList_recursive(input) == *expected);
};

TEST_CASE("problem 206 single")
{
    ListNode *input = new ListNode(5);

    ListNode *expected = new ListNode(5);

    CHECK(*reverseList_iterative(input) == *expected);
};

TEST_CASE("problem 206 single")
{
    ListNode *input = new ListNode(5);

    ListNode *expected = new ListNode(5);

    CHECK(*reverseList_recursive(input) == *expected);
};
