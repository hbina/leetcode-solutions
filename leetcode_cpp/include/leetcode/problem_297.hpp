#include "../data_structure/tree_node.hpp"

#include "../util/string/split.hpp"
#include "../util/generic/is_number.hpp"

#include <algorithm>
#include <string>
#include <memory>
#include <cassert>
#include <vector>
#include <type_traits>

namespace leetcode
{

//  FIXME   ::  Must verify the size of data because we know the relationship
//              between the depth and the number of nodes that must be in it.
//              This is counting the NULL too.
template <typename T>
class Codec
{

private:
    static TreeNode<T> *
    parse_data(
        const std::string &iter)
    {
        if (util::generic::is_number(iter))
        {
            return new TreeNode<T>(std::stoi(iter));
        }
        else
        {
            return nullptr;
        }
    }

public:
    //  Encodes a tree to a single string.
    //  TODO    ::  Rework this mess...
    static std::string
    serialize(const TreeNode<T> *root)
    {
        if (!root)
        {
            return "[]";
        }
        std::string result = "[";
        std::vector<const TreeNode<T> *> layers = {root};
        while (!layers.empty())
        {
            std::vector<const TreeNode<T> *> next_layers;
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

    //  Decodes your encoded data to tree.
    //  Example input: [1,2,null,3,4]
    //  Returns:
    //                  1
    //          2               null
    //      3       4       null    null
    static TreeNode<T> *
    deserialize(const std::string &data)
    {
        std::string skip_bracket = data.substr(1, data.length() - 2);
        std::string delimiter = ",";
        std::vector<std::string> deflatten_data =
            util::string::split<
                std::vector<std::string>>(skip_bracket,
                                          delimiter);
        std::vector<TreeNode<T> *> nodes;
        std::transform(
            deflatten_data.cbegin(),
            deflatten_data.cend(),
            std::back_inserter(nodes),
            [&](const std::string &data) -> TreeNode<T> * {
                return Codec::parse_data(data);
            });
        std::size_t counter = 0;
        std::size_t left_child = 2 * counter + 1;
        std::size_t right_child = 2 * counter + 2;
        for (;;)
        {
            if (left_child < nodes.size())
                nodes[counter]->left = nodes[left_child];
            else
            {
                break;
            }
            if (right_child < nodes.size())
            {
                nodes[counter]->right = nodes[right_child];
            }
            else
            {
                break;
            }
            counter++;
            left_child = 2 * counter + 1;
            right_child = 2 * counter + 2;
        }
        return nodes.empty() ? nullptr : nodes.front();
    }
};

}; // namespace leetcode
