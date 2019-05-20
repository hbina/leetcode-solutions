#include <vector>
#include <iostream>
#include <cassert>

using std::vector;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        if (nums.size() == 0)
        {
            return 0;
        }

        double sum_cache = 0;

        for (const int &a : nums)
        {
            sum_cache += a;
        }

        if (nums.size() < k)
        {
            return sum_cache / nums.size();
        }

        double max_average = sum_cache;

        for (int a = 1; a <= nums.size() - k; a++)
        {
            sum_cache = sum_cache - nums[a - 1] + nums[a + k - 1];

            if (sum_cache > max_average)
            {
                max_average = sum_cache;
            }
        }

        return max_average / k;
    }
};

int main()
{
    Solution s;

    vector<int> s1{1, 12, -5, -6, 50, 3};
    assert(s.findMaxAverage(s1, 4) == 12.75);

    vector<int> s2;
    assert(s.findMaxAverage(s2, 4) == 0);

    vector<int> s3{1, 12, -5, -6};
    assert(s.findMaxAverage(s3, 4) == 0.5);
}
