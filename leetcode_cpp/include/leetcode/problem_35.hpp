#include <vector>
#include <algorithm>

namespace leetcode
{

template <typename T>
static constexpr auto
searchInsert(
    const std::vector<T> &nums,
    const T &target)
    -> typename std::vector<T>::difference_type
{
    return std::distance(
        std::cbegin(nums),
        std::lower_bound(
            std::cbegin(nums),
            std::cend(nums),
            target));
}

} // namespace leetcode