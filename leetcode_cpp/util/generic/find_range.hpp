#include <algorithm>
#include <iterator>
#include <type_traits>

namespace util
{

namespace generic
{

//  TODO    ::  Verify templates
template <
    typename IteratorLhs,
    typename IteratorRhs,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<IteratorLhs>::value_type,
            typename std::iterator_traits<IteratorRhs>::value_type>>>
IteratorLhs find_range(
    IteratorLhs lhs_begin,
    IteratorLhs lhs_end,
    IteratorRhs rhs_begin,
    IteratorRhs rhs_end)
{
    std::size_t lhs_length = std::distance(lhs_begin, lhs_end);
    std::size_t rhs_length = std::distance(rhs_begin, rhs_end);
    if (lhs_length < rhs_length)
    {
        return lhs_end;
    }
    else if (rhs_length == 0)
    {
        return lhs_begin;
    }
    else
    {
        const auto fe = lhs_end - rhs_length + 1;
        while (lhs_begin != fe)
        {
            auto [iter_lhs, iter_rhs] = std::mismatch(lhs_begin, lhs_end, rhs_begin, rhs_end);
            const auto ff = lhs_begin + rhs_length;
            if (iter_lhs == ff && iter_rhs == rhs_end)
            {
                return lhs_begin;
            }
            else
            {
                lhs_begin++;
            }
        }
        return lhs_end;
    }
}

}; // namespace generic

}; // namespace util
