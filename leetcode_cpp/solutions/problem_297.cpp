#include <doctest/doctest.h>

#include "../data_structure/tree_node.hpp"

#include "../util/string/split.hpp"

#include <string>
#include <memory>
#include <cassert>
#include <vector>
#include <type_traits>

template <typename T>
class Codec
{

private:
    //  FIXME   ::  This function is only valid for numeric T.
    //  FIXME   ::  Improve this function by making it consume a view or iterators to begin and end instead.
    template <
        typename Iterator,
        typename = std::enable_if<
            std::is_same_v<
                typename std::iterator_traits<Iterator>::value_type,
                std::string>>>
    static std::pair<TreeNode<T> *, std::size_t>
    consume(
        const Iterator &data_begin,
        const Iterator &data_end)
    {
        if (data_begin == data_end)
        {
            return {nullptr, 0};
        }
        else if (std::distance(data_begin, data_end) == 3)
        {
            return {new TreeNode<T>(
                        0,
                        nullptr,
                        nullptr),
                    0 + 0};
        }
        else
        {
            //  This should never happen because we must guarantee that there are at least 3 elements in a non-trivial case.
            //  At which point the (N-3)th node must not perform any recursion call as the last 2 are 'null's.
            return {new TreeNode<T>(
                        0,
                        nullptr,
                        nullptr),
                    0 + 0};
        }
    }

public:
    // Encodes a tree to a single string.
    static std::string
    serialize(const std::unique_ptr<TreeNode<T>> &root)
    {
        if (!root)
        {
            return "[]";
        }
        std::string result = "[";
        std::vector<TreeNode<T> *> layers = {root.get()};
        while (!layers.empty())
        {
            std::vector<TreeNode<T> *> next_layers;
            for (const TreeNode<T> *node : layers)
            {
                result += std::to_string(node->val) + ",";

                if (node->left)
                {
                    next_layers.push_back(node->left);
                }
                else
                {
                    result += "null,";
                }

                if (node->right)
                {
                    next_layers.push_back(node->right);
                }
                else
                {
                    result += "null,";
                }
            }
            layers = std::move(next_layers);
        }

        // Replace the last char ',' with ']'
        result[result.length() - 1] = ']';
        return result;
    }

    // Decodes your encoded data to tree.
    static TreeNode<T> *deserialize(const std::string &data)
    {
        std::string skip_bracket = data.substr(1, data.length() - 2);
        std::string delimiter = ",";
        std::vector<std::string> deflatten_data =
            util::string::split<
                std::vector<std::string>>(skip_bracket,
                                          delimiter);
        std::pair<TreeNode<T> *, std::size_t> result = consume<>(
            deflatten_data.cbegin(),
            deflatten_data.cend());
        return result.first;
    }
};

TEST_CASE("Problem 297 -- most trivial case")
{
    std::unique_ptr<TreeNode<int>> expected(nullptr);
    std::unique_ptr<TreeNode<int>> input(nullptr);
    std::unique_ptr<TreeNode<int>> result(Codec<int>::deserialize(Codec<int>::serialize(input)));
    // CHECK(expected == result);
}

TEST_CASE("Problem 297 -- basic case")
{
    std::unique_ptr<TreeNode<int>> expected(new TreeNode<>(1));
    std::unique_ptr<TreeNode<int>> input(new TreeNode<>(1));
    std::unique_ptr<TreeNode<int>> result(Codec<int>::deserialize(Codec<int>::serialize(input)));
    // CHECK(*expected == *result);
}

TEST_CASE("Problem 297")
{
    std::unique_ptr<TreeNode<int>> expected(
        new TreeNode<>(1,
                       new TreeNode<>(2),
                       new TreeNode<>(3,
                                      new TreeNode<>(4),
                                      new TreeNode<>(5))));
    std::unique_ptr<TreeNode<int>> input(
        new TreeNode<>(1,
                       new TreeNode<>(2),
                       new TreeNode<>(3,
                                      new TreeNode<>(4),
                                      new TreeNode<>(5))));
    std::unique_ptr<TreeNode<int>> result(Codec<int>::deserialize(Codec<int>::serialize(input)));
    // CHECK(*expected == *result);
}
