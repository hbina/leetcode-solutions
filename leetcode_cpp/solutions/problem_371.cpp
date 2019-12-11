#include "doctest/doctest.h"

#include <utility>
#include <iostream>
#include <bitset>

std::pair<int, int> full_adder(int a, int b, int c)
{
    return {(a ^ b) ^ c, ((a ^ b) & c) | (a & b)};
}

template <typename T>
T getSum(T x, T y)
{
    std::bitset<std::numeric_limits<T>::digits> a1(0);
    std::bitset<std::numeric_limits<T>::digits> b1(x);
    std::bitset<std::numeric_limits<T>::digits> c1(y);
    std::cerr << a1 << ":" << b1 << ":" << c1 << '\n';
    while (y != 0)
    {
        T carry = x & y;
        x = x ^ y;
        y = carry << 1;
        std::bitset<std::numeric_limits<T>::digits> a(carry);
        std::bitset<std::numeric_limits<T>::digits> b(x);
        std::bitset<std::numeric_limits<T>::digits> c(y);
        std::cerr << a << ":" << b << ":" << c << '\n';
    }
    return x;
};

TEST_CASE("problem 371")
{
    // CHECK(3 == getSum(1, 2));
    // CHECK(7 == getSum(5, 2));
    // CHECK(-1 == getSum(-3, 2));
    // CHECK(8 == getSum(10, -2));
    // CHECK(5 == getSum(3, 2));
    // CHECK(-11 == getSum(-11, 0));
    // CHECK(0 == getSum(0, 0));
    CHECK(0 == getSum(-1, 1));
};
