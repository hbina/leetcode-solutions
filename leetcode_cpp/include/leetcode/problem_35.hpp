#include <vector>
#include <algorithm>
#include <iterator>

namespace leetcode
{

template <
    typename Iterable>
static constexpr auto
searchInsert(
    const Iterable &nums,
    const typename Iterable::value_type &target)
    -> typename Iterable::difference_type
{
    return std::distance(
        std::cbegin(nums),
        std::lower_bound(
            std::cbegin(nums),
            std::cend(nums),
            target));
}

} // namespace leetcode