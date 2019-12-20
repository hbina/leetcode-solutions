#include <vector>
#include <algorithm>

namespace leetcode
{

template <typename T>
static constexpr T heightChecker(const std::vector<T> &heights)
{
    std::vector<T> copy = heights;
    std::sort(copy.begin(), copy.end());
    T counter = 0;
    for (std::size_t iter = 0; iter < heights.size(); iter++)
    {
        if (copy[iter] != heights[iter])
            counter++;
    }
    return counter;
}

template <typename T>
static constexpr std::size_t heightChecker_zip(const std::vector<T> &heights)
{
    // FIXME :: There must be a more natural construct to zip through 2 iterators...cmon <algorithm>
    std::vector<T> copy = heights;
    std::sort(copy.begin(), copy.end());
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < copy.size() && iter < heights.size(); iter++)
    {
        const T p_left = heights[iter];
        const T p_right = copy[iter];
        if (p_left != p_right)
            counter++;
    }
    return counter;
}

}; // namespace leetcode
