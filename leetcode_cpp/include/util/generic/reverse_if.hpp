#pragma once

#include <algorithm>

namespace util
{
namespace generic
{

template <
    typename Iterator,
    typename UnaryPredicate>
static constexpr void
reverse_if(
    Iterator iter_begin,
    Iterator iter_end,
    const UnaryPredicate &pred)
{
    auto length = std::distance(iter_begin, iter_end);
    if (length == 0)
        return;
    decltype(length) left_iter = 0;
    decltype(length) right_iter = 1;

    while (left_iter + right_iter <= length - 1)
    {
        while (!pred(*(iter_begin + left_iter)) && left_iter + right_iter <= length - 1)
            left_iter++;
        while (!pred(*(iter_end - right_iter)) && left_iter + right_iter <= length - 1)
            right_iter++;
        if (left_iter + right_iter <= length - 1)
        {
            std::swap(*(iter_begin + left_iter), *(iter_end - right_iter));
            left_iter++;
            right_iter++;
        }
    }
}

} // namespace generic
} // namespace util
