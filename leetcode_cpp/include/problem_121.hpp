#include <iterator>
#include <algorithm>

namespace leetcode
{

template <
    typename Iterable,
    typename T = typename std::iterator_traits<
        typename Iterable::iterator>::value_type>
static constexpr T
maxProfit_One(const Iterable &prices)
{
    T global_profit = T{};

    // Find the first profit that we can make.
    // We also finds our first global_min as a result.
    auto range = std::is_sorted_until(
        std::cbegin(prices),
        std::cend(prices),
        [](const auto &lhs, const auto &rhs) -> bool {
            return lhs < rhs;
        });
    auto [global_min, global_max] = std::minmax_element(std::cbegin(prices), range);
    if (global_min == std::cend(prices) || global_max == std::cend(prices))
        return 0;
    global_profit = *global_max - *global_min;
    while (range != std::cend(prices))
    {
        auto next_max = std::is_sorted_until(
            range,
            std::cend(prices),
            [](const auto &lhs, const auto &rhs) -> bool {
                return lhs < rhs;
            });
        auto [local_min, local_max] = std::minmax_element(range, next_max);

        // If we reset the global min, we must reset global max too
        // because min value must be on the left.
        if (*global_min > *local_min)
        {
            global_max = local_max;
            global_min = local_min;
        }
        else
        {
            if (*global_max < *local_max)
            {
                global_max = local_max;
            }
        }
        range = next_max;
        global_profit = std::max(*global_max - *global_min, global_profit);
    }
    return global_profit;
}

}; // namespace leetcode
