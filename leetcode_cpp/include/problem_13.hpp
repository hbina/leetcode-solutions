#include <string>
#include <map>

namespace leetcode
{

template <typename T = int>
static constexpr T
romanToInt(const std::string &s)
{
    T sum = 0;
    std::map<char, T> nums;

    nums['I'] = 1;
    nums['V'] = 5;
    nums['X'] = 10;
    nums['L'] = 50;
    nums['C'] = 100;
    nums['D'] = 500;
    nums['M'] = 1000;

    for (std::size_t iter = 0; iter < s.size(); iter++)
    {
        if (nums[s[iter]] >= nums[s[iter + 1]])
        {
            sum += nums[s[iter]];
        }
        else
        {
            sum += nums[s[iter + 1]] - nums[s[iter]];
            iter++;
        }
    }

    return sum;
}

} // namespace leetcode
