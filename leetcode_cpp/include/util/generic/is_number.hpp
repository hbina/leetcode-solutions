#pragma once

#include <algorithm>
#include <string>
#include <type_traits>
#include <iterator>

namespace util
{
namespace generic
{

template <typename Iterable>
static constexpr bool
is_number(const Iterable &s)
{
    using T = typename std::iterator_traits<
        typename Iterable::iterator>::value_type;
    return !s.empty() &&
           std::find_if(s.begin(),
                        s.end(),
                        [](const T &c) { return !std::isdigit(c); }) == s.end();
}

} // namespace generic
} // namespace util
