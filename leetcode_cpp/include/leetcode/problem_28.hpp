#pragma once

#include "util/generic/find_range.hpp"

namespace leetcode
{

template <typename Iterable>
static constexpr int
strStr(
    const Iterable &haystack,
    const Iterable &needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }
    using IteratorType = typename Iterable::const_iterator;
    const IteratorType result = util::generic::find_range(
        std::cbegin(haystack),
        std::cend(haystack),
        std::cbegin(needle),
        std::cend(needle));
    return result == std::cend(haystack) ? -1 : static_cast<int>(std::distance(std::cbegin(haystack), result));
}

}; // namespace leetcode
