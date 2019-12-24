#include <string>
#include <algorithm>

template <typename T>
static constexpr bool
is_vowel(const T &x)
{
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
           x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
}

namespace leetcode
{

template <typename Iterable>
static constexpr Iterable
reverseVowels(const Iterable &s)
{
    using CharType = typename std::iterator_traits<
        typename Iterable::iterator>::value_type;
    Iterable letters;
    letters.reserve(s.size());
    std::copy_if(
        s.crbegin(),
        s.crend(),
        std::back_inserter(letters),
        is_vowel<CharType>);
    Iterable result = s;
    std::transform(
        s.cbegin(),
        s.cend(),
        result.begin(),
        [c = letters.cbegin()](const CharType &x) mutable {
            return is_vowel(x) ? *(c++) : x;
        });
    return result;
}

} // namespace leetcode
