#include "doctest/doctest.h"

#include <vector>
#include <iostream>
#include <cassert>

double findMaxAverage(std::vector<int> &nums, std::size_t k)
{

    if (nums.size() == 0)
    {
        return 0;
    }

    double sum_cache = 0;

    for (const int &a : nums)
    {
        sum_cache += a;
    }

    if (nums.size() < k)
    {
        return sum_cache / nums.size();
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
}