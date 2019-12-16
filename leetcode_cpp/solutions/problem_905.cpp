#include "doctest/doctest.h"

#include <vector>
#include <algorithm>

template <typename T>
static constexpr std::vector<T> sortArrayByParity(
    const std::vector<T> &A)
{
    std::vector<T> result;
    result.reserve(A.size());

    for (const T &value : A)
    {
        if (!(value % 2))
        {
            result.push_back(value);
        }
    }
    for (const T &value : A)
    {
        if (value % 2)
        {
            result.push_back(value);
        }
    }
    return result;
}

template <typename T>
static constexpr std::vector<T> sortArrayByParity_stdStablePartition(
    std::vector<T> &result)
{
    std::stable_partition(result.begin(), result.end(), [](const T &a) -> bool {
        return !(a % 2);
    });
    return result;
}

TEST_CASE("problem 905 -- basic test")
{
    std::vector<int> input = {3, 1, 2, 4};
    const std::vector<int> expected = {2, 4, 3, 1};
    CHECK(expected == sortArrayByParity(input));
}

TEST_CASE("problem 905 -- stdSort -- basic test")
{
    std::vector<int> input = {3, 1, 2, 4};
    const std::vector<int> expected = {2, 4, 3, 1};
    CHECK(expected == sortArrayByParity_stdStablePartition(input));
}

TEST_CASE("problem 905 -- long input")
{
    std::vector<int> input = {3363, 4833, 290, 3381, 4227, 1711, 1253, 2984, 2212, 874, 2358, 2049, 2846, 2543, 1557, 1786, 4189, 1254, 2803, 62, 3708, 1679, 228, 1404, 1200, 4766, 1761, 1439, 1796, 4735, 3169, 3106, 3578, 1940, 2072, 3254, 7, 961, 1672, 1197, 3187, 1893, 4377, 2841, 2072, 2011, 3509, 2091, 3311, 233};
    const std::vector<int> expected = {290, 2984, 2212, 874, 2358, 2846, 1786, 1254, 62, 3708, 228, 1404, 1200, 4766, 1796, 3106, 3578, 1940, 2072, 3254, 1672, 2072, 3363, 4833, 3381, 4227, 1711, 1253, 2049, 2543, 1557, 4189, 2803, 1679, 1761, 1439, 4735, 3169, 7, 961, 1197, 3187, 1893, 4377, 2841, 2011, 3509, 2091, 3311, 233};
    CHECK(expected == sortArrayByParity(input));
}

TEST_CASE("problem 905 -- version 2 -- long input")
{
    std::vector<int> input = {3363, 4833, 290, 3381, 4227, 1711, 1253, 2984, 2212, 874, 2358, 2049, 2846, 2543, 1557, 1786, 4189, 1254, 2803, 62, 3708, 1679, 228, 1404, 1200, 4766, 1761, 1439, 1796, 4735, 3169, 3106, 3578, 1940, 2072, 3254, 7, 961, 1672, 1197, 3187, 1893, 4377, 2841, 2072, 2011, 3509, 2091, 3311, 233};
    const std::vector<int> expected = {290, 2984, 2212, 874, 2358, 2846, 1786, 1254, 62, 3708, 228, 1404, 1200, 4766, 1796, 3106, 3578, 1940, 2072, 3254, 1672, 2072, 3363, 4833, 3381, 4227, 1711, 1253, 2049, 2543, 1557, 4189, 2803, 1679, 1761, 1439, 4735, 3169, 7, 961, 1197, 3187, 1893, 4377, 2841, 2011, 3509, 2091, 3311, 233};
    CHECK(expected == sortArrayByParity_stdStablePartition(input));
}
