#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

#include <vector>
#include <algorithm>
#include <memory>
#include <type_traits>
#include <iterator>

template <typename Iterator,
          typename T,
          typename = std::enable_if_t<
              std::is_same_v<
                  typename std::iterator_traits<Iterator>::value_type,
                  T>>>
static constexpr std::size_t get_dividing_index(
    const Iterator &inorder_begin,
    const Iterator &inorder_end,
    const T &postorder_end)
{
    return std::distance(
        inorder_begin,
        std::find(
            inorder_begin,
            inorder_end,
            postorder_end));
}

template <typename Iterator>
static constexpr TreeNode<typename std::iterator_traits<Iterator>::value_type> *
buildTreeTemplateInPost(
    const Iterator &inorder_begin,
    const Iterator &inorder_end,
    const Iterator &postorder_begin,
    const Iterator &postorder_end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;

    if (inorder_begin == inorder_end && postorder_begin == postorder_end)
        return nullptr;

    std::size_t dividing_index = get_dividing_index(
        inorder_begin,
        inorder_end,
        *(postorder_end - 1));

    TreeNode<T> *root = new TreeNode<T>(*(inorder_begin + dividing_index));

    root->left = buildTreeTemplateInPost(
        inorder_begin,
        inorder_begin + dividing_index,
        postorder_begin,
        postorder_begin + dividing_index);
    root->right = buildTreeTemplateInPost(
        inorder_begin + dividing_index + 1,
        inorder_end,
        postorder_begin + dividing_index,
        postorder_end - 1);
    return root;
}

template <typename T>
static constexpr TreeNode<T> *buildTreeInPost(
    const std::vector<T> &inorder,
    const std::vector<T> &postorder)
{
    return buildTreeTemplateInPost(
        inorder.cbegin(),
        inorder.cend(),
        postorder.cbegin(),
        postorder.cend());
}

TEST_CASE("Problem 106")
{
    std::vector<int> input_1 = {9, 3, 15, 20, 7};
    std::vector<int> input_2 = {9, 15, 7, 20, 3};
    std::unique_ptr<TreeNode<int>> expected(
        new TreeNode<>(3,
                       new TreeNode<>(9),
                       new TreeNode<>(20,
                                      new TreeNode<>(15),
                                      new TreeNode<>(7))));
    CHECK(*expected == *buildTreeInPost(input_1, input_2));
}
