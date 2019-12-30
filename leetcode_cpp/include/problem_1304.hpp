#include <vector>
#include <algorithm>

namespace leetcode
{

template <
    typename T,
    typename Iterable = std::vector<T>>
Iterable sumZero(const T &n)
{
    using diff_t = typename std::iterator_traits<typename Iterable::iterator>::difference_type;
    Iterable result(static_cast<diff_t>(n));
    std::iota(
        std::begin(result),
        std::end(result),
        -(static_cast<T>(n / 2)));
    if (static_cast<diff_t>(n) % 2 == 0)
    {
        std::for_each(
            std::next(std::begin(result), static_cast<diff_t>(n / 2)),
            std::end(result),
            [](T &value) {
                value++;
            });
    }
    return result;
}

}; // namespace leetcode
