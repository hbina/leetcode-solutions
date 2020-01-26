#pragma once

#include "util/generic/zip.hpp"

#include <iterator>

namespace util
{
namespace generic
{

template <
    typename OutputType,
    typename IteratorLhs,
    typename IteratorRhs,
    typename DotFunction,
    typename AddFunction>
static constexpr auto
zip_accumulate(
    IteratorLhs lhs_begin,
    IteratorLhs lhs_end,
    IteratorRhs rhs_begin,
    IteratorRhs rhs_end,
    OutputType init,
    const DotFunction &dot,
    const AddFunction &add)
    -> OutputType
{
    util::generic::zip(
        lhs_begin,
        lhs_end,
        rhs_begin,
        rhs_end,
        [&](const auto &left, const auto &right) {
            init = add(init, dot(left, right));
        });
    return init;
}

} // namespace generic
} // namespace util
