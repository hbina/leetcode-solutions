#include "doctest/doctest.h"
#include <string>
#include <iostream>

std::string reverseWords(std::string s)
{
    std::string result;
    std::size_t begin_index = 0;
    std::size_t end_index = 0;
    for (const char &a : s)
    {
        if (a != ' ')
        {
            end_index++;
        }
        else
        {
            for (std::size_t backward_iter = end_index - 1; backward_iter >= begin_index; --backward_iter)
            {
                result.push_back(s.at(backward_iter));
            }
            result.push_back(' ');

            end_index++;
            begin_index = end_index;
        }
    }

    end_index--;
    while (end_index >= begin_index)
    {
        result.push_back(s.at(end_index--));
    }

    return result;
}
