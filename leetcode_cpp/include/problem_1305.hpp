#include "../data_structure/tree_node.hpp"

#include <vector>
#include <stack>

template <typename T>
static constexpr std::stack<const TreeNode<T> *>
get_smallest_node(
    const TreeNode<T> *root)
{
    std::stack<const TreeNode<T> *> result;

    if (!root)
        return result;

    result.push(root);
    while (root)
    {
        if (root->left)
        {
            root = root->left;
            result.push(root);
        }
        else if (root->right)
        {
            root = root->right;
            result.push(root);
        }
        else
        {
            root = nullptr;
        }
    }
    return result;
}

//  TODO    ::  Remove heap usages
//  FIXME   ::  Need to look at tree iterator implementation
namespace leetcode
{

template <
    typename T>
static constexpr std::vector<T>
getAllElements(
    const TreeNode<T> *lhs,
    const TreeNode<T> *rhs)
{
    std::vector<T> result;
    std::stack<const TreeNode<T> *> lhs_stack = std::move(get_smallest_node(lhs));
    std::stack<const TreeNode<T> *> rhs_stack = std::move(get_smallest_node(rhs));

    if (!lhs_stack.empty() && !rhs_stack.empty())
    {
        //  Can be replaced with a Comp
    }
    else if (!lhs_stack.empty())
    {
    }
    else
    {
    }
    return result;
}

}; // namespace leetcode
