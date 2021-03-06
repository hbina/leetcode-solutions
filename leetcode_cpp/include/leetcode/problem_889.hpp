#pragma once

#include "data_structure/tree_node.hpp"

#include <cassert>
#include <vector>
#include <algorithm>
#include <memory>
#include <type_traits>
#include <iterator>

namespace leetcode
{

template <typename Iterator>
static constexpr TreeNode<
    typename std::iterator_traits<Iterator>::value_type> *
constructFromPrePostTemplate(
    const Iterator &preorder_begin,
    const Iterator &preorder_end,
    const Iterator &postorder_begin,
    const Iterator &postorder_end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;

    if (preorder_begin == preorder_end && postorder_begin == postorder_end)
        return nullptr;
    else if (
        std::distance(preorder_begin, preorder_end) == 1 &&
        std::distance(postorder_begin, postorder_end) == 1)
    {
        return new TreeNode<T>(*preorder_begin);
    }
    else
    {
        TreeNode<T> *root = new TreeNode<T>(*preorder_begin);

        // Figure out the next element in preorder
        T next_preorder_element = *(preorder_begin + 1);
        std::size_t size_of_partition_B =
            std::distance(
                postorder_begin,
                std::find(
                    postorder_begin,
                    postorder_end,
                    next_preorder_element)) +
            1;
        std::size_t size_of_partition_C =
            std::distance(
                preorder_begin,
                preorder_end) -
            1 - size_of_partition_B;
        root->left = constructFromPrePostTemplate(
            preorder_begin + 1,
            preorder_begin + 1 + size_of_partition_B,
            postorder_begin,
            postorder_begin + size_of_partition_B);
        root->right = constructFromPrePostTemplate(
            preorder_begin + 1 + size_of_partition_B,
            preorder_begin + 1 + size_of_partition_B + size_of_partition_C,
            postorder_begin + size_of_partition_B,
            postorder_begin + size_of_partition_B + size_of_partition_C);
        return root;
    }
}

template <typename T>
static constexpr TreeNode<T> *constructFromPrePost(
    const std::vector<T> &preorder,
    const std::vector<T> &postorder)
{
    return constructFromPrePostTemplate(
        preorder.cbegin(),
        preorder.cend(),
        postorder.cbegin(),
        postorder.cend());
}

} // namespace leetcode
