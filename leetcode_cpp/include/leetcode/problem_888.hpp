#pragma once

#include <vector>

namespace leetcode
{

template <typename T>
static constexpr std::vector<T> fairCandySwap(const std::vector<T> &A, const std::vector<T> &B)
{
    bool flags[100001] = {false};
    T sum_b = 0;
    for (const T &i : B)
    {
        flags[i] = true;
        sum_b += i;
    }

    T sum_a = 0;
    for (const T &i : A)
        sum_a += i;

    std::vector<T> result(2, 0);
    for (const T &i : A)
    {
        const T target = (sum_b - sum_a) / 2 + i;
        if (target >= 0 && target <= 100000 && flags[target])
        {
            result[0] = i;
            result[1] = target;
            break;
        }
    }
    return result;
}

} // namespace leetcode
