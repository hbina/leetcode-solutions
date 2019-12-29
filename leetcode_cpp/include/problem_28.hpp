#include "../util/generic/find_range.hpp"

namespace leetcode
{

template <typename Iterable>
static constexpr int
strStr(
    const Iterable &haystack,
    const Iterable &needle)
{
    const auto result = util::generic::find_range(
        std::cbegin(haystack),
        std::cend(haystack),
        std::cbegin(needle),
        std::cend(needle));
    return result == std::cend(haystack) ? -1 : static_cast<int>(std::distance(std::cbegin(haystack), result));
}

}; // namespace leetcode
