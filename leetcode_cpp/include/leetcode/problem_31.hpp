#include <algorithm>
#include <iterator>

namespace leetcode
{

template <typename Iterable>
static constexpr auto
nextPermutation(Iterable &nums)
    -> void
{
    std::next_permutation(
        std::begin(nums),
        std::end(nums));
}

} // namespace leetcode
