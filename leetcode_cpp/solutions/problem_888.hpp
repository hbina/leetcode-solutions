#pragma once

#include <vector>

namespace Solution
{
std::vector<int> fairCandySwap(std::vector<int> &A, std::vector<int> &B)
{
    bool flags[100001] = {false};
    int sum_b = 0;
    for (int i : B)
    {
        flags[i] = true;
        sum_b += i;
    }

    int sum_a = 0;
    for (int i : A)
        sum_a += i;

    std::vector<int> result(2, 0);
    for (int i : A)
    {
        int target = (sum_b - sum_a) / 2 + i;
        if (target >= 0 && target <= 100000 && flags[target])
        {
            result[0] = i;
            result[1] = target;
            break;
        }
    }
    return result;
}
}; // namespace Solution