#include <vector>

namespace Solution
{
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int iterator_nums1 = 0;
    int iterator_nums2 = 0;

    while (iterator_nums1 < m)
    {
        if (nums2[iterator_nums2] < nums1[iterator_nums1])
        {
            nums1[iterator_nums1 + 1] = nums1[iterator_nums1];
            nums1[iterator_nums1] = nums2[iterator_nums2];
            iterator_nums2++;
        }
        iterator_nums1++;
    }
}
}; // namespace Solution