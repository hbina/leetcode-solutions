#include "doctest/doctest.h"

#include "leetcode/problem_19.hpp"

TEST_CASE("problem_19")
{
    ListNode<> *input_1 =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(3,
                                                     new ListNode<>(4,
                                                                    new ListNode<>(5)))));
    int input_2 = 2;
    ListNode<> *expected =
        new ListNode<>(1,
                     new ListNode<>(2,
                                  new ListNode<>(3,
                                               new ListNode<>(5))));
    ListNode<> *result = leetcode::removeNthFromEnd(input_1, input_2);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_19")
{
    ListNode<> *input_1 =
        new ListNode(1);
    int input_2 = 1;
    ListNode<> *expected = nullptr;
    ListNode<> *result = leetcode::removeNthFromEnd(input_1, input_2);
    CHECK(expected == result);
    delete expected;
    delete result;
}
