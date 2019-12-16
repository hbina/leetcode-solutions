#include "doctest/doctest.h"

#include <algorithm>
#include <vector>
#include <iterator>
#include <type_traits>
#include <iostream>

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
    const T goal_value)
{
    std::vector<T> global_summations;
    global_summations.push_back(0);

    for (const T num : nums)
    {
        std::vector<T> local_summations;
        for (const T m : global_summations)
        {
            local_summations.push_back(m + num);
            local_summations.push_back(m - num);
        }
        global_summations = local_summations;
    }
    return std::count(global_summations.cbegin(), global_summations.cend(), goal_value);
}

TEST_CASE("Problem 494")
{
    const std::vector<int> input_1 = {1, 1, 1, 1, 1};
    const int input_2 = 3;
    const int expected = 5;
    const int result_bruteForce = static_cast<int>(findTargetSumWays_bruteForce(input_1, input_2));
    const int result_memoization = static_cast<int>(findTargetSumWays_memoization(input_1, input_2));
    CHECK(expected == result_bruteForce);
    CHECK(expected == result_memoization);
}

TEST_CASE("Problem 494 -- long input")
{
    const std::vector<int> input_1 = {30, 1, 5, 32, 16, 17, 30, 29, 48, 14, 29, 4, 31, 12, 40, 13, 13, 20, 41, 38};
    const int input_2 = 9;
    const int expected = 6867;
    const int result_bruteForce = static_cast<int>(findTargetSumWays_bruteForce(input_1, input_2));
    const int result_memoization = static_cast<int>(findTargetSumWays_memoization(input_1, input_2));
    CHECK(expected == result_bruteForce);
     CHECK(expected == result_memoization);
}
