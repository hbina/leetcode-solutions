#include "doctest/doctest.h"

#include "../include/problem_21.hpp"

TEST_CASE("problem_21")
{
    ListNode<> *input_1 = new ListNode<>(1,
                                         new ListNode<>(2,
                                                        new ListNode<>(4)));
    ListNode<> *input_2 = new ListNode<>(1,
                                         new ListNode<>(3,
                                                        new ListNode<>(4)));
    ListNode<> *expected = new ListNode<>(1,
                                          new ListNode<>(1,
                                                         new ListNode<>(2,
                                                                        new ListNode<>(3,
                                                                                       new ListNode<>(4,
                                                                                                      new ListNode<>(4))))));
    ListNode<> *result = leetcode::mergeTwoLists(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
