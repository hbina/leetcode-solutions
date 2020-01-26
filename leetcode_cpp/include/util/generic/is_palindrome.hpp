#pragma once

#include <iterator>

namespace util
{
namespace generic
{

template <typename Iterator,
          typename ValueType = typename std::iterator_traits<Iterator>::value_type>
static constexpr auto
is_palindrome_UnCheckedOdd(
    Iterator iter_begin,
    Iterator iter_end)
    -> bool
{
    while (iter_begin != --iter_end)
    {
        if (*(iter_begin++) != *(iter_end))
            return false;
    }
    return *iter_begin == *iter_end;
}

template <typename Iterator,
          typename ValueType = typename std::iterator_traits<Iterator>::value_type>
static constexpr auto
is_palindrome_UnCheckedEven(
    Iterator iter_begin,
    Iterator iter_end)
    -> bool
{
    while (iter_begin != std::next(--iter_end))
    {
        if (*(iter_begin++) != *(iter_end))
            return false;
    }
    return true;
}

template <typename Iterator,
          typename ValueType = typename std::iterator_traits<Iterator>::value_type>
static constexpr auto
is_palindrome(
    Iterator iter_begin,
    Iterator iter_end)
    -> bool
{
    if (std::distance(iter_begin, iter_end) % 2)
        return util::generic::is_palindrome_UnCheckedOdd(iter_begin, iter_end);
    else
        return util::generic::is_palindrome_UnCheckedEven(iter_begin, iter_end);
}

} // namespace generic
} // namespace util
