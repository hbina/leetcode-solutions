#include "doctest/doctest.h"

#include "leetcode/problem_1305.hpp"

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(2,
                       new TreeNode<>(1),
                       new TreeNode<>(4));
    const TreeNode<> *input_2 =
        new TreeNode<>(1,
                       new TreeNode<>(0),
                       new TreeNode<>(3));
    std::vector<int> expected = {0, 1, 1, 2, 3, 4};
    std::vector<int> result = leetcode::getAllElements(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 = nullptr;
    const TreeNode<> *input_2 =
        new TreeNode<>(5,
                       new TreeNode<>(1,
                                      new TreeNode<>(0),
                                      new TreeNode<>(2)),
                       new TreeNode<>(7));
    std::vector<int> expected = {0, 1, 2, 5, 7};
    std::vector<int> result = leetcode::getAllElements(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 = nullptr;
    const TreeNode<> *input_2 = nullptr;
    std::vector<int> expected = {};
    std::vector<int> result = leetcode::getAllElements(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 = nullptr;
    const TreeNode<> *input_2 = new TreeNode<>(5);
    std::vector<int> expected = {5};
    std::vector<int> result = leetcode::getAllElements(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(2,
                       new TreeNode<>(1),
                       new TreeNode<>(4));
    const TreeNode<> *input_2 =
        new TreeNode<>(1,
                       new TreeNode<>(0),
                       new TreeNode<>(3));
    const std::vector<int> expected = {0, 1, 1, 2, 3, 4};
    const std::vector<int> result =
        leetcode::getAllElements_If(
            input_1,
            input_2,
            [](const auto &lhs, const auto &rhs) -> bool {
                return lhs < rhs;
            });
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 = nullptr;
    const TreeNode<> *input_2 =
        new TreeNode<>(5,
                       new TreeNode<>(1,
                                      new TreeNode<>(0),
                                      new TreeNode<>(2)),
                       new TreeNode<>(7));
    const std::vector<int> expected = {0, 1, 2, 5, 7};
    const std::vector<int> result =
        leetcode::getAllElements_If(
            input_1,
            input_2,
            [](const auto &lhs, const auto &rhs) -> bool {
                return lhs < rhs;
            });
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 = nullptr;
    const TreeNode<> *input_2 = nullptr;
    const std::vector<int> expected = {};
    const std::vector<int> result =
        leetcode::getAllElements_If(
            input_1,
            input_2,
            [](const auto &lhs, const auto &rhs) -> bool {
                return lhs < rhs;
            });
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}

TEST_CASE("problem_1305")
{
    const TreeNode<> *input_1 = nullptr;
    const TreeNode<> *input_2 = new TreeNode<>(5);
    const std::vector<int> expected = {5};
    const std::vector<int> result =
        leetcode::getAllElements_If(
            input_1,
            input_2,
            [](const auto &lhs, const auto &rhs) -> bool {
                return lhs < rhs;
            });
    CHECK(expected == result);
    delete input_1;
    delete input_2;
}
