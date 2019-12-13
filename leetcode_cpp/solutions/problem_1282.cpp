#include "doctest/doctest.h"

#include <vector>
#include <map>

std::vector<std::vector<int>> groupThePeople(const std::vector<int> &groupSizes)
{
    std::map<int, std::size_t> mapper;
    std::vector<std::vector<int>> result;

    for (std::size_t id = 0; id < groupSizes.size(); id++)
    {
        std::size_t x = groupSizes[id];
        if (mapper.find(x) == mapper.end())
        {
            mapper[x] = result.size();
            result.push_back({});
        }
        result[mapper[x]].push_back(id);
        if (result[mapper[x]].size() == x)
        {
            mapper.erase(x);
        }
    }
    return result;
}

TEST_CASE("problem 1282")
{
    const std::vector<int> input = {3, 3, 3, 3, 3, 1, 3};
    const std::vector<std::vector<int>> expected = {
        {0, 1, 2},
        {3, 4, 6},
        {5}};
    const std::vector<std::vector<int>>
        result = groupThePeople(input);
    CHECK(expected == result);
}

TEST_CASE("problem 1282")
{
    const std::vector<int> input = {2, 1, 3, 3, 3, 2};
    const std::vector<std::vector<int>>
        expected = {{0, 5},
                    {1},
                    {2, 3, 4}};
    const std::vector<std::vector<int>>
        result = groupThePeople(input);
    CHECK(expected == result);
}
