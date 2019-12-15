#include "doctest/doctest.h"

#include <string>
#include <stack>

//  TODO    ::  Possible to use std::string_view here instead?

std::string decodeString(const std::string &s)
{
    std::string result;
    std::string counter;
    std::stack<std::pair<std::size_t, std::string>> chars;
    for (const auto &x : s)
    {
        switch (x)
        {
        case '[':
        {
            chars.push(std::make_pair(std::stoi(counter), ""));
            counter = "";
            break;
        }
        case ']':
        {
            std::string tmp;
            for (std::size_t iter = 0; iter < chars.top().first; iter++)
            {
                tmp += chars.top().second;
            }
            if (chars.size() == 1)
            {
                result += tmp;
                chars.pop();
            }
            else
            {
                chars.pop();
                chars.top().second += tmp;
            }
            break;
        }
        default:
        {
            if (
                x == '1' || x == '2' || x == '3' || x == '4' || x == '5' ||
                x == '6' || x == '7' || x == '8' || x == '9' || x == '0')
            {
                counter += x;
            }
            else
            {
                if (chars.empty())
                {
                    result += x;
                }
                else
                {
                    chars.top().second += x;
                }
            }
            break;
        }
        }
    }
    return result;
}

TEST_CASE("Problem 394")
{
    CHECK(std::string("aaabcbc") == decodeString("3[a]2[bc]"));
    CHECK(std::string("accaccacc") == decodeString("3[a2[c]]"));
    CHECK(std::string("abcabccdcdcdef") == decodeString("2[abc]3[cd]ef"));
}
