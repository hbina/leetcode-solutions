#include "doctest/doctest.h"

#include "../include/problem_117.hpp"

TEST_CASE("problem_117")
{
    NodeNext<> *input =
        new NodeNext<>(1,
                       new NodeNext<>(2,
                                      new NodeNext<>(4,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      new NodeNext<>(5,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      nullptr),

                       new NodeNext<>(3,
                                      nullptr,
                                      new NodeNext<>(7,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      nullptr),
                       nullptr);
    NodeNext<> *expected_node_7 = new NodeNext<>(7);
    NodeNext<> *expected_node_5 =
        new NodeNext<>(5,
                       nullptr,
                       nullptr,
                       expected_node_7);
    NodeNext<> *expected_node_4 =
        new NodeNext<>(4,
                       nullptr,
                       nullptr,
                       expected_node_5);
    NodeNext<> *expected_node_3 =
        new NodeNext<>(3,
                       nullptr,
                       expected_node_7,
                       nullptr);
    NodeNext<> *expected_node_2 =
        new NodeNext<>(2,
                       expected_node_4,
                       expected_node_5,
                       expected_node_3);
    const NodeNext<> *expected =
        new NodeNext<>(1,
                       expected_node_2,
                       expected_node_3,
                       nullptr);
    const NodeNext<int> *result = leetcode::connect(input);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
