#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

namespace leetcode
{
template <typename T>
static constexpr double findMedianSortedArrays_basic(
    const std::vector<T> &nums1,
    const std::vector<T> &nums2)
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
static constexpr double findMedianSortedArrays_search(
    const std::vector<T> &nums1,
    const std::vector<T> &nums2)
{
    //  TODO    ::  There are better ways to do this than to make a heap allocation
    //              of 2 possibly large vectors. Most of the allocations are wasted anyway,
    //              because we are dealing with medians of sorted arrays, all the information
    //              we need is in the middle.
    return 0.0f;
}
} // namespace leetcode
