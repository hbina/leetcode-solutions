#include <vector>
#include <algorithm>

namespace leetcode
{

template <typename T>
static constexpr std::size_t
removeElement(std::vector<T> &nums, const T &val)
{
    return std::distance(
        std::begin(nums),
        std::remove(
            std::begin(nums),
            std::end(nums),
            val));
}

} // namespace leetcode
