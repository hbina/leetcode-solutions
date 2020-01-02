#include <doctest/doctest.h>

#include "leetcode/problem_297.hpp"

TEST_CASE("problem_297")
{
    TreeNode<int> *input = new TreeNode<>(
        1,
        new TreeNode<>(2),
        new TreeNode<>(3,
                       new TreeNode<>(4),
                       new TreeNode<>(5)));
    // TreeNode<int> *result = Codec<int>::deserialize(Codec<int>::serialize(input));
    // CHECK(*input == *result);
    delete input;
    // delete result;
}
