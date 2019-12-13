#include "doctest/doctest.h"

#include "../data_structure/list_node.hpp"

template <typename T>
constexpr ListNode<T> *reverseList_iterative(ListNode<T> *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode<T> *pointer_before = nullptr;
    ListNode<T> *pointer_current = head;
    ListNode<T> *pointer_after = head->next;

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
}

template <typename T>
constexpr ListNode<T> *reverseList_recursive_helper(ListNode<T> *head, ListNode<T> *next)
{
    // Means that we are at the end.
    if (!next)
    {
        return head;
    }
    else
    {
        ListNode<T> *tmp = next->next;
        next->next = head;
        return reverseList_recursive_helper(next, tmp);
    }
}

template <typename T>
constexpr ListNode<T> *reverseList_recursive(ListNode<T> *head)
{
    if (head)
    {
        ListNode<T> *tmp = head->next;
        head->next = nullptr;
        return reverseList_recursive_helper(head, tmp);
    }
    else
    {
        return nullptr;
    }
}

TEST_CASE("problem 206")
{
    ListNode<int> *input = new ListNode<int>(
        1,
        new ListNode<int>(
            2,
            new ListNode<int>(
                3,
                new ListNode<int>(
                    4,
                    new ListNode<int>(
                        5)))));

    ListNode<int> *expected = new ListNode<int>(
        5,
        new ListNode<int>(
            4,
            new ListNode<int>(
                3,
                new ListNode<int>(
                    2,
                    new ListNode<int>(
                        1)))));

    CHECK(*reverseList_iterative(input) == *expected);
}

TEST_CASE("problem 206")
{
    ListNode<int> *input = new ListNode<int>(
        1,
        new ListNode<int>(
            2,
            new ListNode<int>(
                3,
                new ListNode<int>(
                    4,
                    new ListNode<int>(
                        5)))));

    ListNode<int> *expected = new ListNode<int>(
        5,
        new ListNode<int>(
            4,
            new ListNode<int>(
                3,
                new ListNode<int>(
                    2,
                    new ListNode<int>(
                        1)))));

    CHECK(*reverseList_recursive(input) == *expected);
}

TEST_CASE("problem 206 single")
{
    ListNode<int> *input = new ListNode<int>(5);

    ListNode<int> *expected = new ListNode<int>(5);

    CHECK(*reverseList_iterative(input) == *expected);
}

TEST_CASE("problem 206 single")
{
    ListNode<int> *input = new ListNode<int>(5);

    ListNode<int> *expected = new ListNode<int>(5);

    CHECK(*reverseList_recursive(input) == *expected);
}
