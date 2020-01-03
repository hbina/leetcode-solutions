#pragma once

#include <string>
#include <type_traits>
#include <cassert>
#include <stack>

namespace leetcode
{

//  TODO    ::  Narrow down this template to only accept types that implements std::char_traits
std::size_t balancedStringSplit(const std::string &s)
{
    //  TODO    ::  Impelement this algorithm...it should be simple enough
    std::size_t global_counter = 0;
    int counter = 0;
    for (const auto &x : s)
    {
        if (x == 'L')
        {
            counter--;
        }
        else if (x == 'R')
        {
            counter++;
        }
        else
        {
            assert(false);
        }
        if (counter == 0)
        {
            global_counter++;
        }
    }
    return global_counter;
}

} // namespace leetcode
