#pragma once

#include <vector>
#include <algorithm>

namespace Solution
{
int heightChecker(std::vector<int> &heights)
{
    std::vector<int> copy = heights;
    std::sort(copy.begin(), copy.end());
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < heights.size(); iter++)
    {
        if (copy[iter] != heights[iter])
            counter++;
    }
    return counter;
}

int heightChecker_1(std::vector<int> &heights)
{
    // FIXME :: There must be a more natural construct to zip through 2 iterators...cmon <algorithm>
    std::vector<int> copy = heights;
    std::sort(copy.begin(), copy.end());
    std::size_t counter = 0;
    std::mismatch(heights.cbegin(), heights.cend(),
                  copy.cbegin(),
                  [&](const int p_left, const int p_right) {
                      if (p_left != p_right)
                          counter++;
                      return true;
                  });
    return counter;
}
}; // namespace Solution
