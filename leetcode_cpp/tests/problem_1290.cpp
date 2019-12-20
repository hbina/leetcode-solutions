#include "doctest/doctest.h"

#include "../include/problem_1290.hpp"

TEST_CASE("problem_1290")
{
    ListNode<int> *input = new ListNode<>(0);
    CHECK(0 == leetcode::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    ListNode<int> *input = new ListNode<>(1);
    CHECK(1 == leetcode::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    // lmao
    ListNode<int> *input =
        new ListNode<>(
            1,
            new ListNode<>(0,
                           new ListNode<>(0,
                                          new ListNode<>(1,
                                                         new ListNode<>(0,
                                                                        new ListNode<>(0,
                                                                                       new ListNode<>(1,
                                                                                                      new ListNode<>(1,
                                                                                                                     new ListNode<>(1,
                                                                                                                                    new ListNode<>(0,
                                                                                                                                                   new ListNode<>(0,
                                                                                                                                                                  new ListNode<>(0,
                                                                                                                                                                                 new ListNode<>(0,
                                                                                                                                                                                                new ListNode<>(0,
                                                                                                                                                                                                               new ListNode<>(0)))))))))))))));
    CHECK(
        18880 ==
        leetcode::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    ListNode<int> *input =
        new ListNode<>(
            0,
            new ListNode<>(0));
    CHECK(0 == leetcode::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    ListNode<int> *input =
        new ListNode<>(
            1,
            new ListNode<>(
                0,
                new ListNode<>(1)));
    CHECK(5 == leetcode::getDecimalValue(input));
    delete input;
}
