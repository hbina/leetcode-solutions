#include <algorithm>
#include <string>
#include <vector>

namespace leetcode
{

//  TODO    ::  This can be generalized further...
std::string longestCommonPrefix(const std::vector<std::string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    else if (strs.size() == 1)
    {
        return strs[0];
    }
    else
    {
        bool common = true;
        std::string result;
        std::size_t smallest_string_size = (*std::max_element(
                                                strs.cbegin(),
                                                strs.cend(),
                                                [](const std::string &lhs, const std::string &rhs) -> bool {
                                                    return lhs.size() < rhs.size();
                                                }))
                                               .size();
        for (std::size_t string_iter = 0; common && string_iter < smallest_string_size; string_iter++)
        {
            const char sample = strs[0][string_iter];
            for (std::size_t vector_iter = 1; vector_iter < strs.size(); vector_iter++)
            {
                if (strs[vector_iter][string_iter] != sample)
                {
                    common = false;
                    break;
                }
            }
            if (common)
            {
                result += sample;
            }
        }
        return result;
    }
}

}; // namespace leetcode
