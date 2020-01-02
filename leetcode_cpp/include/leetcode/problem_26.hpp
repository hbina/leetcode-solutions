#pragma once

#include <iterator>
#include <algorithm>

namespace leetcode
{

//  TODO    ::  There is a more general algorithm that can be extracted here...
template <typename Iterable>
static constexpr std::size_t
removeDuplicates(Iterable &nums)
{
    return std::distance(
        std::begin(nums),
        std::unique(
            std::begin(nums),
            std::end(nums)));
}

} // namespace leetcode
