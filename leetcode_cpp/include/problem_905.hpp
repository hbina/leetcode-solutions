
#include <vector>
#include <algorithm>

namespace leetcode
{

template <typename T>
static constexpr std::vector<T> sortArrayByParity(
    const std::vector<T> &A)
{
    std::vector<T> result;
    result.reserve(A.size());

    for (const T &value : A)
    {
        if (!(value % 2))
        {
            result.push_back(value);
        }
    }
    for (const T &value : A)
    {
        if (value % 2)
        {
            result.push_back(value);
        }
    }
    return result;
}

template <typename T>
static constexpr std::vector<T> sortArrayByParity_stdStablePartition(
    std::vector<T> &result)
{
    std::stable_partition(result.begin(), result.end(), [](const T &a) -> bool {
        return !(a % 2);
    });
    return result;
}

}; // namespace leetcode
