#include "doctest/doctest.h"

#include <vector>
#include <algorithm>

template <typename T>
constexpr int heightChecker(const std::vector<T> &heights)
{
    std::vector<T> copy = heights;
    std::sort(copy.begin(), copy.end());
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < heights.size(); iter++)
    {
        if (copy[iter] != heights[iter])
            counter++;
    }
    return counter;
}

template <typename T>
constexpr int heightChecker_zip(const std::vector<T> &heights)
{
    // FIXME :: There must be a more natural construct to zip through 2 iterators...cmon <algorithm>
    std::vector<T> copy = heights;
    std::sort(copy.begin(), copy.end());
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < copy.size() && iter < heights.size(); iter++)
    {
        const T p_left = heights[iter];
        const T p_right = copy[iter];
        if (p_left != p_right)
            counter++;
    }
    return counter;
}

TEST_CASE("Problem 1051")
{
    std::vector<int> test1{1, 1, 4, 2, 1, 3};
    CHECK(3 == heightChecker(test1));
    CHECK(3 == heightChecker_zip(test1));
}
