#include "doctest/doctest.h"

#include <vector>
#include <iostream>
#include <cassert>

template <typename InputType>
double findMaxAverage(std::vector<InputType> &nums, std::size_t k)
{
    double sum_cache = 0.0;

    if (nums.empty())
    {
        return 0.0;
    }

    if (nums.size() < k)
    {
        InputType sum = 0;
        for (const auto &a : nums)
        {
            sum += a;
        }
        return sum / nums.size();
    }

    for (std::size_t a = 0; a < k; a++)
    {
        sum_cache += nums[a];
    }

    double max_average = sum_cache;

    for (std::size_t a = 1; a <= nums.size() - k; a++)
    {
        sum_cache = sum_cache - nums[a - 1] + nums[a + k - 1];

        if (sum_cache > max_average)
        {
            max_average = sum_cache;
        }
    }

    return max_average / k;
};

TEST_CASE("problem 643")
{
    std::vector<int> input_1 = {1, 12, -5, -6, 50, 3};
    std::size_t input_2 = 4;
    double expected = 12.75;
    CHECK(expected == findMaxAverage(input_1, input_2));
};
