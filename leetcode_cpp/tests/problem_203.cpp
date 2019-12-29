#include "doctest/doctest.h"

#include "../include/problem_203.hpp"

TEST_CASE("problem_203")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(6,
                                                     new ListNode<>(3,
                                                                    new ListNode<>(4,
                                                                                   new ListNode<>(5,
                                                                                                  new ListNode<>(6)))))));
    const int input_2 = 6;
    const ListNode<> *expected = new ListNode<>(1,
                                                new ListNode<>(2,
                                                               new ListNode<>(3,
                                                                              new ListNode<>(4,
                                                                                             new ListNode<>(5)))));
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(6,
                                                     new ListNode<>(3,
                                                                    new ListNode<>(4,
                                                                                   new ListNode<>(5,
                                                                                                  new ListNode<>(6)))))));
    const int input_2 = 32;
    const ListNode<> *expected =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(6,
                                                     new ListNode<>(3,
                                                                    new ListNode<>(4,
                                                                                   new ListNode<>(5,
                                                                                                  new ListNode<>(6)))))));
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    ListNode<> *input = new ListNode<>(1);
    const int input_2 = 1;
    const ListNode<> *expected = nullptr;
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(expected == result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    ListNode<> *input = nullptr;
    const int input_2 = 1;
    const ListNode<> *expected = nullptr;
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(expected == result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(1,
                                      new ListNode<>(1)));
    const int input_2 = 1;
    const ListNode<> *expected = nullptr;
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(expected == result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    ListNode<> *input =
        new ListNode<>(3,
                       new ListNode<>(2,
                                      new ListNode<>(1)));
    const int input_2 = 1;
    const ListNode<> *expected =
        new ListNode<>(3,
                       new ListNode<>(2));
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(6,
                                                     new ListNode<>(3,
                                                                    new ListNode<>(4,
                                                                                   new ListNode<>(5,
                                                                                                  new ListNode<>(6)))))));
    const int input_2 = 6;
    const ListNode<> *expected = new ListNode<>(1,
                                                new ListNode<>(2,
                                                               new ListNode<>(3,
                                                                              new ListNode<>(4,
                                                                                             new ListNode<>(5)))));
    ListNode<> *result = leetcode::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203 -- If")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(6,
                                                     new ListNode<>(3,
                                                                    new ListNode<>(4,
                                                                                   new ListNode<>(5,
                                                                                                  new ListNode<>(6)))))));
    const ListNode<> *expected =
        new ListNode<>(1,
                       new ListNode<>(3,
                                      new ListNode<>(5)));
    ListNode<> *result = leetcode::removeElements_If(
        input,
        [](const int &val) -> bool {
            return val % 2 == 0;
        });
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
