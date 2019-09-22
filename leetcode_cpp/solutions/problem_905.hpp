#include <vector>
#include <algorithm>

namespace Solution
{
std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    std::vector<int> result;
    result.reserve(result.size());

    for (int const &value : A)
    {
        if (!(value % 2))
        {
            result.push_back(value);
        }
    }
    for (int const &value : A)
    {
        if (value % 2)
        {
            result.push_back(value);
        }
    }
    return result;
}

std::vector<int> sortArrayByParity_modernCPP(std::vector<int> &A)
{
    std::vector<int> result(A);
    std::sort(result.begin, result.end, [](int &a, int &b) {
        return a % 2;
    });
    return result;
}
}; // namespace Solution
