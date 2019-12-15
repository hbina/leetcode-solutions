#include "doctest/doctest.h"

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
static constexpr double findMedianSortedArrays_naive(const std::vector<T> &nums1, const std::vector<T> &nums2)
{
    std::vector<T> collection;
    collection.reserve(nums1.size() + nums2.size());
    collection.insert(collection.end(), nums1.begin(), nums1.end());
    collection.insert(collection.end(), nums2.begin(), nums2.end());
    std::sort(collection.begin(), collection.end());
    if (collection.size() % 2 == 0)
    {
        double left = collection[collection.size() / 2 - 1];
        double right = collection[collection.size() / 2];
        return (left + right) / 2;
    }
    else
    {
        return collection[static_cast<std::size_t>(collection.size() / 2)];
    }
}

template <typename T>
static constexpr double findMedianSortedArrays_search(std::vector<T> &nums1, std::vector<T> &nums2)
{
    //  TODO    ::  There are better ways to do this than to make a heap allocation
    //              of 2 possibly large vectors. Most of the allocations are wasted anyway,
    //              because we are dealing with medians of sorted arrays, all the information
    //              we need is in the middle.
    return 0.0f;
}

TEST_CASE("problem 4")
{
    std::vector<int> input_1 = {1, 3};
    std::vector<int> input_2 = {2};
    CHECK(2.0 == findMedianSortedArrays_naive(input_1, input_2));
}

TEST_CASE("problem 4")
{
    std::vector<int> input_1 = {1, 2};
    std::vector<int> input_2 = {3, 4};
    CHECK(2.5 == findMedianSortedArrays_naive(input_1, input_2));
}
