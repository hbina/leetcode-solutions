#include <unordered_set>
#include <type_traits>

//  TODO    ::  Implement set_equality_If
namespace util
{
namespace generic
{

template <
    typename IteratorLhs,
    typename IteratorRhs,
    typename = std::enable_if<
        std::is_same_v<
            typename std::iterator_traits<IteratorLhs>::value_type,
            typename std::iterator_traits<IteratorRhs>::value_type>>>
static constexpr auto
set_equality(
    IteratorLhs lhs_begin,
    IteratorLhs lhs_end,
    IteratorRhs rhs_begin,
    IteratorRhs rhs_end)
    -> bool
{
    using T = std::common_type_t<
        typename std::iterator_traits<IteratorLhs>::value_type,
        typename std::iterator_traits<IteratorRhs>::value_type>;
    const auto lhs = std::unordered_set<T>(lhs_begin, lhs_end);
    const auto rhs = std::unordered_set<T>(rhs_begin, rhs_end);
    return lhs == rhs;
}

template <
    typename IteratorLhs,
    typename IteratorRhs,
    typename = std::enable_if<
        std::is_same_v<
            typename IteratorLhs::value_type,
            typename IteratorRhs::value_type>>>
static constexpr bool
set_equality(
    IteratorLhs lhs,
    IteratorRhs rhs)
{
    return set_equality(
        std::cbegin(lhs),
        std::cend(lhs),
        std::cbegin(rhs),
        std::cend(rhs));
}

} // namespace generic
} // namespace util
