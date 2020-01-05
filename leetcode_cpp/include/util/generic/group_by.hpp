#pragma once

#include <iterator>
#include <numeric>

namespace util
{
namespace generic
{

//  TODO    ::  Allow user to specify OutputIteratorType
//  FIXME   ::  Requires a humongous amount of memory allocations...
template <
    typename OutputIteratorType,
    typename Iterator,
    typename BinaryPredicate>
static constexpr OutputIteratorType
group_by(
    Iterator iter_begin,
    Iterator iter_end,
    const BinaryPredicate &pred)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    return std::accumulate(
        std::next(iter_begin),
        iter_end,
        OutputIteratorType{{*iter_begin}},
        [&](OutputIteratorType &acc,
            const T &rhs)
            -> OutputIteratorType {
            if (pred(acc.back().back(), rhs))
            {
                acc.back().push_back(rhs);
            }
            else
            {
                acc.push_back({rhs});
            }
            return acc;
        });
}

} // namespace generic
} // namespace util
