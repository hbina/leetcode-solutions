#pragma once

#include "data_structure/tree_node.hpp"

#include <vector>
#include <algorithm>
#include <type_traits>
#include <iterator>
#include <memory>

template <typename Iterator,
          typename T,
          typename = std::enable_if_t<
              std::is_same_v<
                  typename std::iterator_traits<Iterator>::value_type,
                  T>>>
static constexpr std::size_t
get_dividing_index(
    const Iterator &preorder_begin,
    const Iterator &preorder_end,
    const T &inorder_end)
{
    return std::distance(
        preorder_begin,
        std::find(
            preorder_begin,
            preorder_end,
            inorder_end));
}

template <typename Iterator>
static constexpr TreeNode<
    typename std::iterator_traits<Iterator>::value_type> *
buildTreeTemplatePreIn(
    const Iterator &preorder_begin,
    const Iterator &preorder_end,
    const Iterator &inorder_begin,
    const Iterator &inorder_end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;

    if (preorder_begin == preorder_end && inorder_begin == inorder_end)
        return nullptr;

    std::size_t dividing_index = get_dividing_index(
        inorder_begin,
        inorder_end,
        *(preorder_begin));

    TreeNode<T> *root = new TreeNode<T>(*preorder_begin);

    root->left = buildTreeTemplatePreIn(
        preorder_begin + 1,
        preorder_begin + dividing_index + 1,
        inorder_begin,
        inorder_begin + dividing_index);
    root->right = buildTreeTemplatePreIn(
        preorder_begin + dividing_index + 1,
        preorder_end,
        inorder_begin + dividing_index + 1,
        inorder_end);
    return root;
}

namespace leetcode
{

template <typename T>
static constexpr TreeNode<T> *
buildTreePreIn(
    const std::vector<T> &preorder,
    const std::vector<T> &inorder)
{
    return buildTreeTemplatePreIn(
        preorder.cbegin(),
        preorder.cend(),
        inorder.cbegin(),
        inorder.cend());
}

}; // namespace leetcode
