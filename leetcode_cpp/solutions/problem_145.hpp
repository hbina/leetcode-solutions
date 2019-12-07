#include "../data_structure/tree_node.hpp"

#include <vector>
#include <stack>
#include <iostream>

namespace Solution
{

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
}; // namespace Solution
