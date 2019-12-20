#include "doctest/doctest.h"

#include "../include/problem_589.hpp"

TEST_CASE("problem_589 -- iterative")
{
    const Node<> *input =
        new Node<>(1,
                   {new Node<>(3,
                               {new Node<>(5),
                                new Node<>(6)}),
                    new Node<>(2),
                    new Node<>(4)});
    const std::vector<int> expected = {1, 3, 5, 6, 2, 4};
    const std::vector<int> result = leetcode::preorder_iterative(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_589 -- recursive")
{
    const Node<> *input =
        new Node<>(1,
                   {new Node<>(3,
                               {new Node<>(5),
                                new Node<>(6)}),
                    new Node<>(2),
                    new Node<>(4)});
    const std::vector<int> expected = {1, 3, 5, 6, 2, 4};
    const std::vector<int> result = leetcode::preorder_recursive(input);
    CHECK(expected == result);
    delete input;
}
