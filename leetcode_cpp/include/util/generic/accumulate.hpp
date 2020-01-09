#include <type_traits>

namespace util
{
namespace generic
{

template <typename NumType,
          typename ResultType,
          typename AccumulateFunction,
          typename = std::enable_if<
              std::is_integral_v<NumType>>>
static constexpr auto accumulate(
    NumType begin,
    const NumType &end,
    ResultType acc,
    const AccumulateFunction &adder) -> ResultType
{
    while (begin != end)
    {
        acc = adder(acc, begin);
        begin++;
    }
    return acc;
}

} // namespace generic
} // namespace util
