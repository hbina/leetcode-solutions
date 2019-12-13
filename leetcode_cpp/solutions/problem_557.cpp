#include "doctest/doctest.h"

#include <string>
#include <vector>

template <typename T>
T reverseWords(const T &input)
{
    T result;
    std::vector<T> collector;
    T tmp;

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

TEST_CASE("problem 557")
{
    const std::string input = "Let's take LeetCode contest";
    const std::string expected = "s'teL ekat edoCteeL tsetnoc";
    CHECK(expected == reverseWords(input));
}
