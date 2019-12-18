#include "doctest/doctest.h"

#include <string>
#include <vector>

std::string reverseWords(const std::string &input)
{
    std::string result;
    std::vector<std::string> collector;
    std::string tmp;

    for (auto riter = input.rbegin(); riter != input.rend(); riter++)
    {
        if (*riter == ' ')
        {
            if (!tmp.empty())
            {
                collector.push_back(tmp);
                tmp.clear();
            }
        }
        else
        {
            tmp.push_back(*riter);
        }
    }
    if (!tmp.empty())
    {
        collector.push_back(tmp);
    }
    for (auto riter = collector.rbegin(); riter != collector.rend(); riter++)
    {
        result += *riter + ' ';
    }
    return result.substr(0, result.length() - 1);
}

TEST_CASE("problem_557")
{
    const std::string input = "Let's take LeetCode contest";
    const std::string expected = "s'teL ekat edoCteeL tsetnoc";
    const std::string result = reverseWords(input);
    CHECK(expected == result);
}
