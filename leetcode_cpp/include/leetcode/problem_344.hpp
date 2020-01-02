#pragma once

#include <vector>
#include <algorithm>

namespace leetcode
{

void reverseString(std::vector<char> &s)
{
    std::reverse(s.begin(), s.end());
}

} // namespace leetcode
