#include <iterator>
#include <algorithm>

namespace leetcode
{

template <typename Iterable,
          typename T = typename std::iterator_traits<
              typename Iterable::iterator>::value_type>
static constexpr auto
search_TypeTwo(
    Iterable &nums,
    const T &target)
    -> bool
{
    if (nums.empty())
    {
        return false;
    }

    auto iter_begin = std::begin(nums);
    auto iter_end = std::unique(
        std::begin(nums),
        std::end(nums));

    auto pivot = std::is_sorted_until(
        iter_begin,
        iter_end);

    if (nums.front() > target)
    {
        return std::binary_search(
            pivot,
            iter_end,
            target);
    }
    else
    {
        return std::binary_search(
            iter_begin,
            pivot,
            target);
    }
}

} // namespace leetcode
