#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>

namespace Solution
{
int numUniqueEmails(const std::vector<std::string> &emails)
{
    std::unordered_map<std::string, int> map;
    for (const std::string &email : emails)
    {
        std::string temp;
        bool skipping_plus = false;
        bool skipping_dot = true;
        for (const char &a : email)
        {
            if (a == '+')
            {
                skipping_plus = true;
            }
            else if (a == '@')
            {
                skipping_dot = false;
                skipping_plus = false;
            }

            if (skipping_plus)
            {
                continue;
            }
            else if (a == '.' && skipping_dot)
            {
                continue;
            }
            else
            {
                temp += a;
            }
        }
        std::cout << "temp:" << temp << std::endl;
        map[temp]++;
    }
    return map.size();
}
}; // namespace Solution
