#include "doctest/doctest.h"

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void merge_simple(
    std::vector<T> &nums1, std::size_t m,
    const std::vector<T> &nums2, std::size_t n)
{
    for (std::size_t counter = 0; counter < n; counter++)
    {
        nums1[m + counter] = nums2[counter];
    }
    std::sort(nums1.begin(), nums1.end());
}

TEST_CASE("problem_88")
{
    const std::vector<int> expected = {1, 2, 2, 3, 5, 6};
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    const std::vector<int> nums2 = {2, 5, 6};
    merge_simple(nums1, 3, nums2, 3);
    CHECK(expected == nums1);
}
