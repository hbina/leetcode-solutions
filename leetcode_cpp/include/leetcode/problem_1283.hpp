#pragma once

#include <algorithm>
#include <vector>
#include <numeric>

namespace leetcode
{

template <typename T>
static constexpr T specialDivision(const T &value, const T &divisor)
{
    const T remainder = value % divisor;
    const T division = (value - remainder) / divisor;
    if (remainder == 0)
    {
        return division;
    }
    else
    {
        return division + 1;
    }
}

template <typename T>
static constexpr T accumulateResult(const std::vector<T> &nums, const T &divisor)
{
    return std::accumulate(nums.cbegin(), nums.cend(), 0, [&](T sum, const T &x) -> T {
        return std::move(sum) + specialDivision(x, divisor);
    });
}

template <typename T>
static constexpr T smallestDivisor_naive(const std::vector<T> &nums, T threshold)
{
    T divisor = 1;
    T result = accumulateResult(nums, divisor);
    while (result > threshold)
    {
        divisor++;
        result = accumulateResult(nums, divisor);
    }
    return divisor;
}

template <typename T>
static constexpr T smallestDivisor_guessFirst(const std::vector<T> &nums, T threshold)
{
    T sum = accumulateResult(nums, 1);
    T guess_divisor = sum / threshold;
    if (guess_divisor == 0)
    {
        return 1;
    }
    T result = accumulateResult(nums, guess_divisor);
    while (result > threshold)
    {
        guess_divisor++;
        result = accumulateResult(nums, guess_divisor);
    }
    return guess_divisor;
}

} // namespace leetcode
