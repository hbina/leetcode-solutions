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
    delete input_1;
    delete input_2;
}
