#pragma once

#include "data_structure/tree_node.hpp"
#include "data_structure/bst_iterator.hpp"

#include <vector>
#include <stack>

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

    leetcode::BSTIterator<int> *lhs_iterator =
        new leetcode::BSTIterator<int>(lhs);
    leetcode::BSTIterator<int> *rhs_iterator =
        new leetcode::BSTIterator<int>(rhs);

    if (!lhs_iterator->hasNext() && !rhs_iterator->hasNext())
    {
        //  Can be replaced with a Comp
    }
    else if (!lhs_iterator->hasNext())
    {
    }
    else if (!rhs_iterator->hasNext())
    {
    }

    return result;
}

}; // namespace leetcode
