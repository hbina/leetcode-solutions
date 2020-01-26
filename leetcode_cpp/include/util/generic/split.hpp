#pragma once

#include <algorithm>
#include <type_traits>
#include <vector>
#include <iterator>

namespace util
{
namespace generic
{

template <
    typename T,
    typename OutputIteratorInner = std::vector<T>,
    typename OutputIteratorOuter = std::vector<OutputIteratorInner>,
    typename InputIterator,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<InputIterator>::value_type,
            typename std::iterator_traits<
                typename OutputIteratorInner::iterator>::value_type>>,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<InputIterator>::value_type,
            T>>>
static constexpr auto
split(
    InputIterator iter_begin,
    InputIterator iter_end,
    const T &delimiter)
    -> OutputIteratorOuter
{
    OutputIteratorOuter result;
    while (iter_begin != iter_end && (*iter_begin == delimiter))
        iter_begin = std::next(iter_begin);
    while (iter_begin != iter_end)
    {
        auto iter_until = std::next(iter_begin);
        while (iter_until != iter_end && (*iter_until != delimiter))
            iter_until = std::next(iter_until);
        result.emplace_back(iter_begin, iter_until);
        iter_begin = iter_until;
        while (iter_begin != iter_end && (*iter_begin == delimiter))
            iter_begin = std::next(iter_begin);
    }
    return result;
}

template <
    typename T,
    typename OutputIteratorInner = std::vector<T>,
    typename OutputIteratorOuter = std::vector<OutputIteratorInner>,
    typename InputIterator,
    typename UnaryPredicate,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<InputIterator>::value_type,
            typename std::iterator_traits<typename OutputIteratorInner::iterator>::value_type>>>
static constexpr auto
split_if(
    InputIterator iter_begin,
    InputIterator iter_end,
    const UnaryPredicate &predicate)
    -> OutputIteratorOuter
{
    OutputIteratorOuter result;
    while (iter_begin != iter_end && predicate(*iter_begin))
        iter_begin = std::next(iter_begin);
    while (iter_begin != iter_end)
    {
        auto iter_until = std::next(iter_begin);
        while (iter_until != iter_end && !predicate(*iter_until))
            iter_until = std::next(iter_until);
        result.emplace_back(iter_begin, iter_until);
        iter_begin = iter_until;
        while (iter_begin != iter_end && predicate(*iter_begin))
            iter_begin = std::next(iter_begin);
    }
    return result;
}

} // namespace generic
} // namespace util
