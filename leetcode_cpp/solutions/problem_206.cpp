#include "doctest/doctest.h"

#include "../data_structure/list_node.hpp"

template <typename T>
static constexpr ListNode<T> *reverseList_iterative(
    ListNode<T> *head)
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
static constexpr ListNode<T> *reverseList_recursive_helper(
    ListNode<T> *head,
    ListNode<T> *next)
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
static constexpr ListNode<T> *reverseList_recursive(ListNode<T> *head)
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

TEST_CASE("problem_206")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(
                           2,
                           new ListNode<>(
                               3,
                               new ListNode<>(
                                   4,
                                   new ListNode<>(
                                       5)))));

    const ListNode<> *expected =
        new ListNode<>(5,
                       new ListNode<>(
                           4,
                           new ListNode<>(
                               3,
                               new ListNode<>(
                                   2,
                                   new ListNode<>(
                                       1)))));
    const ListNode<> *result = reverseList_iterative(input);
    CHECK(*result == *expected);
    delete result;
    delete expected;
}

TEST_CASE("problem_206")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(
                           2,
                           new ListNode<>(
                               3,
                               new ListNode<>(
                                   4,
                                   new ListNode<>(
                                       5)))));

    const ListNode<> *expected =
        new ListNode<>(5,
                       new ListNode<>(
                           4,
                           new ListNode<>(
                               3,
                               new ListNode<>(
                                   2,
                                   new ListNode<>(
                                       1)))));

    const ListNode<> *result = reverseList_iterative(input);
    CHECK(*result == *expected);
    delete result;
    delete expected;
}

TEST_CASE("problem_206 single")
{
    ListNode<> *input = new ListNode<>(5);

    const ListNode<> *expected = new ListNode<>(5);

    const ListNode<> *result = reverseList_iterative(input);

    CHECK(*result == *expected);
    delete input;
    delete expected;
}

TEST_CASE("problem_206 single")
{
    ListNode<> *input = new ListNode<>(5);
    const ListNode<> *expected = new ListNode<>(5);
    const ListNode<> *result = reverseList_recursive(input);
    CHECK(*result == *expected);
    delete input;
    delete expected;
}
