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
    typename T,
    typename BinaryPredicate>
static std::vector<T>
getAllElements_If(
    const TreeNode<T> *lhs,
    const TreeNode<T> *rhs,
    const BinaryPredicate &pred)
{
    std::vector<T> result;

    leetcode::BSTIterator<T> lhs_iterator =
        leetcode::BSTIterator<T>(lhs);
    leetcode::BSTIterator<T> rhs_iterator =
        leetcode::BSTIterator<T>(rhs);

    while (lhs_iterator.hasNext() && rhs_iterator.hasNext())
    {
        //  Can be replaced with a Comp
        if (pred(lhs_iterator.peek()->val, rhs_iterator.peek()->val))
            result.push_back(lhs_iterator.next()->val);
        else
            result.push_back(rhs_iterator.next()->val);
    }
    while (lhs_iterator.hasNext())
        result.push_back(lhs_iterator.next()->val);
    while (rhs_iterator.hasNext())
        result.push_back(rhs_iterator.next()->val);

    return result;
}

template <
    typename T>
static std::vector<T>
getAllElements(
    const TreeNode<T> *lhs,
    const TreeNode<T> *rhs)
{
    return getAllElements_If(lhs, rhs, std::less{});
}

}; // namespace leetcode
