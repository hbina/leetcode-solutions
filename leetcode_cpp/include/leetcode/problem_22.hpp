#pragma once

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
    typename NumType,
    typename ReturnType = std::vector<std::string>>
static constexpr auto
generateParenthesis(const NumType &n)
    -> ReturnType
{
    using SizeType = typename ReturnType::size_type;
    auto result = ReturnType{"()"};
    for (NumType outer = 1; outer != n; outer++)
    {
        SizeType saved_size = result.size();
        for (SizeType inner = 0; inner != saved_size; inner++)
        {
            result.emplace_back("()" + result[inner]);
            result.emplace_back(result[inner] + "()");
            result.emplace_back("(" + result[inner] + ")");
        }
    }
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
