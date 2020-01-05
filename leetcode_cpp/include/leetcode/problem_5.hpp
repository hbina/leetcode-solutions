#pragma once

#include <string>
#include <vector>
#include <algorithm>

template <
    typename StringType,
    typename SizeType = typename StringType::size_type>
static constexpr auto
expand_around_center(
    const StringType &s,
    const SizeType &left,
    const SizeType &right)
    -> SizeType
{
    SizeType L = left + 1, R = right;
    while (L > 0u && R < s.size() && s[L - 1] == s[R])
    {
        L--;
        R++;
    }
    return R - L;
}

namespace leetcode
{

template <
    typename StringType,
    typename SizeType = typename StringType::size_type>
static constexpr auto
longestPalindrome(const StringType &s)
    -> StringType
{
    if (s.size() < 1)
        return {};
    SizeType start = 0, end = 0;
    for (SizeType i = 0; i < s.size(); i++)
    {
        SizeType len1 = expand_around_center(s, i, i);
        SizeType len2 = expand_around_center(s, i, i + 1);
        SizeType len = std::max(len1, len2);
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return {std::next(std::cbegin(s), start), std::next(std::cbegin(s), end + 1)};
}

} // namespace leetcode
