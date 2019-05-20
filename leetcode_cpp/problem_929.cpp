#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>

using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    int numUniqueEmails(const vector<string> &emails)
    {
        unordered_map<string, int> map;
        for (const string &email : emails)
        {
            string temp;
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
};

int main()
{
    Solution s;

    const vector<string> s1{
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"};
    assert(s.numUniqueEmails(s1) == 2);
}