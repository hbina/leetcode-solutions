#include "doctest/doctest.h"

#include "../include/problem_206.hpp"

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
    const ListNode<> *result = leetcode::reverseList_iterative(input);
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

    const ListNode<> *result = leetcode::reverseList_iterative(input);
    CHECK(*result == *expected);
    delete result;
    delete expected;
}

TEST_CASE("problem_206 single")
{
    ListNode<> *input = new ListNode<>(5);

    const ListNode<> *expected = new ListNode<>(5);

    const ListNode<> *result = leetcode::reverseList_iterative(input);

    CHECK(*result == *expected);
    delete input;
    delete expected;
}

TEST_CASE("problem_206 single")
{
    ListNode<> *input = new ListNode<>(5);
    const ListNode<> *expected = new ListNode<>(5);
    const ListNode<> *result = leetcode::reverseList_recursive(input);
    CHECK(*result == *expected);
    delete input;
    delete expected;
}
