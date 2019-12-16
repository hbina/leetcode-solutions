#include <algorithm>
#include <string>
#include <type_traits>
#include <iterator>

namespace util
{
namespace string
{

template <typename Iterable>
bool is_number(const Iterable &s)
{
    using T = std::iterator_traits<Iterable::iterator>::value_type;
    return !s.empty() &&
           std::find_if(s.begin(),
                        s.end(),
                        [](char c) { return !std::isdigit(c); }) == s.end();
}

} // namespace string
} // namespace util
