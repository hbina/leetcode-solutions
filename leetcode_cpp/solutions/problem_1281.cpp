#include "doctest/doctest.h"

#include <numeric>
#include <vector>

template <typename T>
constexpr T subtractProductAndSum(const T &input)
{
    T n = input;
    std::vector<T> collection;
    while (n)
    {
        T tmp = n % 10;
        collection.push_back(tmp);
        n /= 10;
    }

    return std::accumulate(collection.begin(), collection.end(), 1, std::multiplies<T>()) -
           std::accumulate(collection.begin(), collection.end(), 0);
};

TEST_CASE("problem 1281")
{
    CHECK(15 == subtractProductAndSum(234));
    CHECK(21 == subtractProductAndSum(4421));
};
