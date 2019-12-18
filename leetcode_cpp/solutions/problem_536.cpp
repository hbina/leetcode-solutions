#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

template <typename T>
bool isMirror(const TreeNode<T> *lhs, const TreeNode<T> *rhs)
{
    if (lhs == nullptr && rhs == nullptr)
        return true;
    if (lhs == nullptr || rhs == nullptr)
        return false;
    return lhs->val == rhs->val &&
           isMirror(lhs->right, rhs->left) &&
           isMirror(lhs->left, rhs->right);
}

template <typename T>
bool isSymmetric(const TreeNode<T> *root)
{
    return isMirror(root, root);
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       new TreeNode<>(2,
                                      new TreeNode<>(3),
                                      new TreeNode<>(4)),
                       new TreeNode<>(2,
                                      new TreeNode<>(4),
                                      new TreeNode<>(3)));
    bool expected = true;
    bool result = isSymmetric(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       new TreeNode<>(2,
                                      new TreeNode<>(3),
                                      new TreeNode<>(2)),
                       new TreeNode<>(2,
                                      new TreeNode<>(4),
                                      new TreeNode<>(3)));
    const bool expected = false;
    bool result = isSymmetric(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input = new TreeNode<>(1);
    const bool expected = true;
    bool result = isSymmetric(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_536")
{
    const TreeNode<> *input = nullptr;
    const bool expected = true;
    bool result = isSymmetric(input);
    CHECK(expected == result);
}
