

namespace leetcode
{

template <typename NumType>
static constexpr auto
maximum69Number(NumType num)
    -> NumType
{
    NumType result = NumType{};
    while (num)
    {
        
        num /= 10;
    }
    return result;
}

} // namespace leetcode
