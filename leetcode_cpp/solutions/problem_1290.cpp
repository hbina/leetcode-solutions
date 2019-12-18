#include "doctest/doctest.h"

#include "../data_structure/list_node.hpp"

#include <memory>

template <typename T>
std::size_t getDecimalValue(const ListNode<T> *head)
{
    std::size_t result = 0;
    std::size_t pow = 1;
    while (head)
    {
        result = result << 1;
        result |= head->val;
        head = head->next;
    }
    return result;
}

TEST_CASE("problem_1290")
{
    CHECK(0 == getDecimalValue(
                   std::make_unique<ListNode<int>>(
                       0)
                       .get()));
    CHECK(1 == getDecimalValue(
                   std::make_unique<ListNode<int>>(
                       1)
                       .get()));

    // lmao
    CHECK(
        18880 ==
        getDecimalValue(
            std::make_unique<ListNode<>>(
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
                                                                                                                                                                                                                   new ListNode<>(0)))))))))))))))
                .get()));
    CHECK(0 == getDecimalValue(
                   std::make_unique<ListNode<int>>(
                       0,
                       new ListNode<>(0))
                       .get()));
    CHECK(5 == getDecimalValue(
                   std::make_unique<ListNode<int>>(
                       1,
                       new ListNode<>(0,
                                      new ListNode<>(1)))
                       .get()));
}
