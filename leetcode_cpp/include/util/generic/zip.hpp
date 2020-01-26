#pragma once

#include <iterator>

namespace util
{
namespace generic
{

template <
    typename IteratorLhs,
    typename IteratorRhs,
    typename BinaryFunction>
static constexpr void
zip(
    IteratorLhs iter_lhs_begin,
    IteratorLhs iter_lhs_end,
    IteratorRhs iter_rhs_begin,
    IteratorRhs iter_rhs_end,
    const BinaryFunction &fun)
{
    while (iter_lhs_begin != iter_lhs_end && iter_rhs_begin != iter_rhs_end)
    {
        fun(*iter_lhs_begin, *iter_rhs_begin);
        iter_lhs_begin++;
        iter_rhs_begin++;
    }
}

} // namespace generic
} // namespace util
