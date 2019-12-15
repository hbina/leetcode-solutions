#include <doctest/doctest.h>

#include "../data_structure/tree_node.hpp"

#include <string>
#include <memory>

template <typename T>
class Codec
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode<T> *root)
    {
    }

    // Decodes your encoded data to tree.
    TreeNode<T> *deserialize(std::string data)
    {
    }
};

TEST_CASE("Problem 297")
{
    std::unique_ptr<TreeNode<int>> expected(
        new TreeNode<>(1,
                       new TreeNode<>(2),
                       new TreeNode<>(3,
                                      new TreeNode<>(4),
                                      new TreeNode<>(5))));
}
