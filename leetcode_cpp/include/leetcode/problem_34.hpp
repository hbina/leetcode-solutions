#include <vector>
#include <algorithm>

namespace leetcode
{

template <typename Iterable>
static constexpr auto
searchRange(
    const Iterable &nums,
    const typename Iterable::value_type &target)
    -> std::vector<int>
{
    const auto upper_bound = std::upper_bound(
        std::cbegin(nums),
        std::cend(nums),
        target);
    const auto lower_bound = std::lower_bound(
        std::cbegin(nums),
        std::cend(nums),
        target);
    if (lower_bound == upper_bound)
    {
        return {-1, -1};
    }
    else
    {
        return {
            static_cast<int>(std::distance(
                std::cbegin(nums),
                lower_bound)),
            static_cast<int>(std::distance(
                std::cbegin(nums),
                upper_bound)) -
                1};
    }
}

} // namespace leetcode