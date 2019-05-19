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

    void test()
    {
        vector<int> s{1, 12, -5, -6, 50, 3};
        assert(findMaxAverage(s, 4) == 12.75);

        vector<int> s1;
        assert(findMaxAverage(s1, 4) == 0);

        vector<int> s3{1, 12, -5, -6};
        assert(findMaxAverage(s3, 4) == 0.5);
    }
};

int main()
{
    Solution s;
    s.test();
}