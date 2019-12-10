#include "string_util.hpp"

bool is_string_equal(std::string &str1, std::string &str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    else if (str1.size() == 0)
    {
        return true;
    }
    else
    {
        for (std::size_t iter = 0; iter < str1.size(); iter++)
        {
            if (str1[iter] != str2[iter])
            {
                return false;
            }
        }
        return true;
    }
}
