#pragma once

#include <vector>
#include <map>

namespace leetcode
{

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

} // namespace leetcode
