#include "doctest/doctest.h"

#include "../data_structure/tree_node.hpp"

#include <vector>
#include <algorithm>
#include <type_traits>
#include <iterator>

//  FIXME   ::  Can be improved by removing all those memory copying. Create a new function that accepts
//              std::vector<T>::const_iterator instead.

template <typename Iterator,
          typename T,
          typename = std::enable_if_t<
              std::is_same_v<
                  typename std::iterator_traits<Iterator>::value_type,
                  T>>>
std::size_t get_dividing_index(
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
TreeNode<typename std::iterator_traits<Iterator>::value_type> *buildTreeTemplate(
    const Iterator &inorder_begin,
    const Iterator &inorder_end,
    const Iterator &postorder_begin,
    const Iterator &postorder_end)
{
    if (inorder_begin == inorder_end && postorder_begin == postorder_end)
        return nullptr;

    std::size_t dividing_index = get_dividing_index(
        inorder_begin,
        inorder_end,
        *(postorder_end - 1));

    TreeNode<int> *root = new TreeNode<int>(*(inorder_begin + dividing_index));

    root->left = buildTreeTemplate(
        inorder_begin,
        inorder_begin + dividing_index,
        postorder_begin,
        postorder_begin + dividing_index);
    root->right = buildTreeTemplate(
        inorder_begin + dividing_index + 1,
        inorder_end,
        postorder_begin + dividing_index,
        postorder_end - 1);
    return root;
}

template <typename T>
TreeNode<T> *buildTree(
    const std::vector<T> &inorder,
    const std::vector<T> &postorder)
{
    return buildTreeTemplate(
        inorder.cbegin(),
        inorder.cend(),
        postorder.cbegin(),
        postorder.cend());
}

TEST_CASE("Problem 942")
{
    std::vector<int> input_1 = {9, 3, 15, 20, 7};
    std::vector<int> input_2 = {9, 15, 7, 20, 3};
    TreeNode<int> *expected = new TreeNode<int>(3,
                                                new TreeNode<int>(9),
                                                new TreeNode<int>(20,
                                                                  new TreeNode<int>(15),
                                                                  new TreeNode<int>(7)));
    CHECK(*expected == *buildTree(input_1, input_2));
}
