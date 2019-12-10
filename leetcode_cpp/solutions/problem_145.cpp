#include "doctest/doctest.h"

#include <vector>
#include <stack>
#include <iostream>

#include "../data_structure/tree_node.hpp"

// Solution using recursion
std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> AB, A, B;
    if (root)
    {
        if (root->left)
        {
            A = postorderTraversal(root->left);
        }
        if (root->right)
        {
            B = postorderTraversal(root->right);
        }
        AB.reserve(A.size() + B.size() + 1);
        AB.insert(AB.end(), A.begin(), A.end());
        AB.insert(AB.end(), B.begin(), B.end());
        AB.push_back(root->val);
    }
    return AB;
}

TEST_CASE("Problem 145")
{
    TreeNode *root = new TreeNode(
        1,
        nullptr,
        new TreeNode(
            2,
            new TreeNode(
                3,
                nullptr,
                nullptr),
            nullptr));

    std::vector<int> result = postorderTraversal(root);
    std::vector<int> expected = {3, 2, 1};
    CHECK(result.size() == expected.size());
    for (std::size_t iter = 0; iter < result.size(); iter++)
    {
        CHECK(result[iter] == expected[iter]);
    }
};
