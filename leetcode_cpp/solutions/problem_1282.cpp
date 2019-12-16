#include "doctest/doctest.h"

#include <vector>
#include <map>

template <typename T>
std::vector<std::vector<T>> groupThePeople(const std::vector<T> &groupSizes)
{
    std::map<T, std::size_t> mapper;
    std::vector<std::vector<T>> result;

    for (std::size_t id = 0; id < groupSizes.size(); id++)
    {
        T x = static_cast<T>(groupSizes[id]);
        if (mapper.find(x) == mapper.end())
        {
            mapper[x] = result.size();
            result.push_back({});
        }
        result[static_cast<T>(mapper[x])].push_back(static_cast<T>(id));
        if (result[mapper[x]].size() == static_cast<std::size_t>(x))
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
