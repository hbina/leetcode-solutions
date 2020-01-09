#pragma once

#include "util/generic/accumulate.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

namespace leetcode
{

//  TODO    ::  This algorithm performs a fuckton of allocations.
//              There ought to be a solution that only allocate once for the result.
//              Basically have to reuse the original result.
//              What we could do is simply:
//              1.  Push stuff into the result vector
//              2.  Filter result based on the length
//              3.  Filter result based on uniqueness
template <
    typename NumType>
static constexpr auto
generateParenthesis(const NumType &n)
    -> std::vector<std::string>
{
    auto result = util::generic::accumulate(
        1, n, std::vector<std::string>{"()"},
        [](std::vector<std::string> &acc, const auto &index) {
            return util::generic::accumulate(
                std::vector<std::string>::size_type{}, acc.size(), acc,
                [](std::vector<std::string> &acc, const auto &index) {
                    acc.emplace_back("()" + acc[index]);
                    acc.emplace_back(acc[index] + "()");
                    acc.emplace_back("(" + acc[index] + ")");
                    return acc;
                });
        });
    result.resize(
        std::distance(
            std::begin(result),
            std::remove_if(
                std::begin(result),
                std::end(result),
                [&](const std::string &value) -> bool {
                    return value.size() != static_cast<std::string::size_type>(n * 2);
                })));
    std::sort(std::begin(result), std::end(result));
    result.resize(
        std::distance(
            std::begin(result),
            std::unique(
                std::begin(result),
                std::end(result))));
    return result;
}

} // namespace leetcode
