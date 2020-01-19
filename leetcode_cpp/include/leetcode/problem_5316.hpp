#include <vector>
#include <string>

#include "util/generic/split.hpp"

namespace leetcode
{

static auto
printVertically(const std::string &s)
    -> std::vector<std::string>
{
    using CharT = std::string::value_type;
    const std::vector<std::string> split =
        util::generic::split_if<
            CharT,
            std::string>(
            std::cbegin(s),
            std::cend(s),
            [](const CharT &value) -> bool {
                return value == ' ';
            });
    return split;
}

}; // namespace leetcode
