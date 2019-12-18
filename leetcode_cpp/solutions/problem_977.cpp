#include "doctest/doctest.h"

#include <vector>
#include <algorithm>

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

TEST_CASE("problem_977")
{
    std::vector<int> input = {-4, -1, 0, 3, 10};
    const std::vector<int> expected = {0, 1, 9, 16, 100};
    sortedSquares(input);
    CHECK(expected == input);
}

TEST_CASE("problem_977")
{
    std::vector<int> input = {-7, -3, 2, 3, 11};
    const std::vector<int> expected = {4, 9, 9, 49, 121};
    sortedSquares(input);
    CHECK(expected == input);
}
