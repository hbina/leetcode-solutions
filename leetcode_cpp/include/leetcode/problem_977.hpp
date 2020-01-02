#include <vector>
#include <algorithm>

namespace leetcode
{

template <typename T>
static constexpr std::vector<T> sortedSquares(
    std::vector<T> &A)
{
    std::for_each(A.begin(), A.end(), [](auto &x) -> void {
        x *= x;
    });
    std::sort(A.begin(), A.end(), [](const auto &lhs, const auto &rhs) -> bool {
        return lhs < rhs;
    });
    return A;
}

}; // namespace leetcode
