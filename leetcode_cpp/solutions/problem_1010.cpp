#include "doctest/doctest.h"

#include <algorithm>
#include <vector>
#include <unordered_map>

int numPairsDivisibleBy60(std::vector<int> &time)
{
    std::vector<int> map(60, 0);
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < time.size(); ++iter)
    {
        int val = time[iter] % 60;
        int diff = 60 - val;
        if (diff == 60)
            diff = 0;
        counter += map[diff];
        map[val]++;
    }
    return counter;
}

// NOTE :: This is a pretty bad algorithm that is O(n^2)
int numPairsDivisibleBy60_O2(std::vector<int> &time)
{
    std::size_t counter = 0;
    for (std::size_t iter1 = 0; iter1 < time.size(); iter1++)
    {
        for (std::size_t iter = iter1 + 1; iter < time.size(); iter++)
        {
            if (((time[iter] + time[iter1]) % 60) == 0)
                counter++;
        }
    }
    return counter;
}

TEST_CASE("Problem 1010")
{
    std::vector<int> test1{30, 20, 150, 100, 40};
    CHECK(3 == numPairsDivisibleBy60(test1));
};
