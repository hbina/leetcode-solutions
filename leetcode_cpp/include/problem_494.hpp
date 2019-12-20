#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <type_traits>
#include <iostream>

namespace leetcode
{

template <typename Iterator,
          typename T = typename std::iterator_traits<Iterator>::value_type>
static constexpr std::size_t findTargetSumWays_bruteForce_Iterator(
    Iterator iter_begin,
    Iterator iter_end,
    const T &goal_value)
{
    if (iter_begin == iter_end)
    {
        return 0;
    }
    else if (std::distance(iter_begin, iter_end) == 1)
    {
        if (*iter_begin == goal_value && -(*iter_begin) == goal_value)
        {
            return 2;
        }
        else if (*iter_begin == goal_value || -(*iter_begin) == goal_value)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return findTargetSumWays_bruteForce_Iterator(iter_begin + 1, iter_end, goal_value + (*iter_begin)) +
               findTargetSumWays_bruteForce_Iterator(iter_begin + 1, iter_end, goal_value - (*iter_begin));
    }
}

template <typename Iterable,
          typename T = typename std::iterator_traits<
              typename Iterable::iterator>::value_type>
static constexpr std::size_t findTargetSumWays_bruteForce(
    const Iterable &nums,
    const T &goal_value)
{
    return findTargetSumWays_bruteForce_Iterator(
        nums.cbegin(),
        nums.cend(),
        goal_value);
}

template <typename Iterable,
          typename T = typename std::iterator_traits<
              typename Iterable::iterator>::value_type>
static constexpr std::size_t findTargetSumWays_memoization(
    const Iterable &nums,
    const T &goal_value)
{
    std::unordered_map<T, std::size_t> global_summations;
    global_summations.emplace(0, 1);

    for (const T &num : nums)
    {
        std::unordered_map<T, std::size_t> local_summations;
        for (const auto &[key, value] : global_summations)
        {
            local_summations[key + num] = local_summations[key + num] + global_summations[key];
            local_summations[key - num] = local_summations[key - num] + global_summations[key];
        }
        global_summations = std::move(local_summations);
    }
    return global_summations[goal_value];
}

}; // namespace leetcode
