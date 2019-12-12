#include "doctest/doctest.h"

#include <vector>
#include <iostream>
#include <algorithm>

void merge_simple(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    for (int counter = 0; counter < n; counter++)
    {
        nums1[m + counter] = nums2[counter];
    }
    std::sort(nums1.begin(), nums1.end());
}

TEST_CASE("problem 88")
{
    std::vector<int> expected = {1, 2, 2, 3, 5, 6};
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    merge_simple(nums1, 3, nums2, 3);
    CHECK(expected == nums1);
};
