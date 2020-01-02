#pragma once

#include <algorithm>
#include <iterator>

namespace leetcode
{

template <typename Iterable,
          typename T = typename std::iterator_traits<
              typename Iterable::iterator>::value_type>
static constexpr auto
search_TypeOne(
    const Iterable &nums,
    const T &target)
    -> int
{
    if (nums.empty())
    {
        return -1;
    }

    auto pivot = std::is_sorted_until(
        std::cbegin(nums),
        std::cend(nums));

    if (nums.front() > target)
    {
        auto result = std::lower_bound(
            pivot,
            std::cend(nums),
            target);
        return result == std::cend(nums) || *result > target
                   ? -1
                   : static_cast<int>(std::distance(std::cbegin(nums), result));
    }
    else
    {
        auto result = std::lower_bound(
            std::cbegin(nums),
            pivot,
            target);
        return result == pivot || *result > target
                   ? -1
                   : static_cast<int>(std::distance(
                         std::cbegin(nums),
                         result));
    }
}

}; // namespace leetcode
