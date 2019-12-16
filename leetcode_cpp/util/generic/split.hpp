#include <algorithm>
#include <type_traits>
#include <iterator>

namespace util
{
namespace generic
{
template <
    typename OutputIteratorOuter,
    typename OutputIteratorInner,
    typename InputIterator,
    typename UnaryPredicate,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<InputIterator>::value_type,
            typename std::iterator_traits<typename OutputIteratorInner::iterator>::value_type>>>
OutputIteratorOuter split_if(
    InputIterator iter_begin,
    InputIterator iter_end,
    const UnaryPredicate &predicate)
{
    OutputIteratorOuter result;
    auto find_if = std::find_if(
        iter_begin,
        iter_end,
        predicate);
    while (find_if != iter_end)
    {
        OutputIteratorInner token(iter_begin, find_if + 1);
        result.push_back(std::move(token));

        iter_begin = find_if + 1;
        find_if = std::find_if(
            iter_begin,
            iter_end,
            predicate);
    }
    if (iter_begin != iter_end)
    {
        OutputIteratorInner token(iter_begin, iter_end);
        result.push_back(std::move(token));
    }
    return result;
}

template <
    typename OutputIteratorOuter,
    typename OutputIteratorInner,
    typename InputIterator,
    typename T,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<InputIterator>::value_type,
            typename std::iterator_traits<typename OutputIteratorInner::iterator>::value_type>>,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<InputIterator>::value_type,
            T>>>
OutputIteratorOuter split(
    InputIterator iter_begin,
    InputIterator iter_end,
    const T &delimiter)
{
    OutputIteratorOuter result;
    auto find = std::find(
        iter_begin,
        iter_end,
        delimiter);
    while (find != iter_end)
    {
        OutputIteratorInner token(iter_begin, find + 1);
        result.push_back(std::move(token));

        iter_begin = find + 1;
        find = std::find(
            iter_begin,
            iter_end,
            delimiter);
    }
    if (iter_begin != iter_end)
    {
        OutputIteratorInner token(iter_begin, iter_end);
        result.push_back(std::move(token));
    }
    return result;
}

} // namespace generic
} // namespace util