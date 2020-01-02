#include "doctest/doctest.h"

#include "leetcode/problem_160.hpp"

TEST_CASE("problem_160")
{
    ListNode<int> *c1 =
        new ListNode<int>(6,
                          new ListNode<int>(
                              7,
                              new ListNode<int>(
                                  8,
                                  nullptr)));
    ListNode<int> *a1 =
        new ListNode<int>(1,
                          new ListNode<int>(
                              2,
                              c1));
    ListNode<int> *b1 =
        new ListNode<int>(3,
                          new ListNode<int>(
                              4,
                              new ListNode<int>(
                                  5,
                                  c1)));
    ListNode<int> *result = leetcode::getIntersectionNode(a1, b1);
    CHECK(*c1 == *result);
    // Solely for cleanup purposes...
    b1->next->next->next = nullptr;
    delete a1;
    delete b1;
}
