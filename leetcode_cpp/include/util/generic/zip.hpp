#pragma once

#include <iterator>

namespace util
{
namespace generic
{

template <
    typename IteratorLhs,
    typename IteratorRhs,
    typename BinaryFunctor>
static constexpr void
zip(
    IteratorLhs iter_lhs_begin,
    IteratorLhs iter_lhs_end,
    IteratorRhs iter_rhs_begin,
    IteratorRhs iter_rhs_end,
    const BinaryFunctor &functor)
{
    while (iter_lhs_begin != iter_lhs_end && iter_rhs_begin != iter_rhs_end)
    {
        functor(*iter_lhs_begin, *iter_rhs_begin);
        iter_lhs_begin++;
        iter_rhs_begin++;
    }
}

} // namespace generic
} // namespace util
