#pragma once

#include <vector>
#include <string>
#include <iterator>
#include <type_traits>
#include <algorithm>
#include <numeric>

namespace leetcode
{

template <
    typename StringType,
    typename MatchType = std::vector<StringType>,
    typename DifferenceType = typename StringType::difference_type,
    typename CharType = typename StringType::value_type>
static constexpr auto findSubstring(
    const StringType &string,
    const MatchType &matches)
    -> std::vector<DifferenceType>
{
    //  NOTE    ::  This is actually a 2 part problem.
    //              1. The first part is finding the occurences of these elements
    //              2. Next is finding the parts that contains all of the matches
    //              We can also optimize a lot of stuff with matches. In particular,
    //              we can removes duplicates when one match is a subset of another match.

    return std::accumulate(
        std::cbegin(string),
        std::cend(string),
        std::vector<DifferenceType>{},
        [](auto &acc, const CharType &value) {
            return acc;
        });
}

} // namespace leetcode
