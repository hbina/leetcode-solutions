
#include <utility>
#include <iostream>
#include <bitset>

namespace leetcode
{

template <typename T>
static constexpr std::pair<T, T> full_adder(const T &a, const T &b, const T &c)
{
    return {(a ^ b) ^ c, ((a ^ b) & c) | (a & b)};
}

template <typename T>
T getSum(const T &x_input, const T &y_input)
{
    T x = x_input;
    T y = y_input;
    while (y != 0)
    {
        T carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

}; // namespace leetcode
