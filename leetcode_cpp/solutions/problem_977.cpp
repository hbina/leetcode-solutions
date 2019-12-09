#include "doctest/doctest.h"

#include <vector>
#include <cassert>

std::vector<int> sortedSquares(std::vector<int> &A)
{

    if (A.size() == 0)
    {
        return std::vector<int>{};
    }

    std::vector<int> s;
    s.reserve(A.size());

    std::size_t going_right = 0;

    while (going_right < A.size() && A[going_right] < 0)
    {
        going_right++;
    }

    std::size_t going_left = going_right - 1;

    // "Zip" through left and right from the middle...
    while (going_left >= 0 && going_right < A.size())
    {
        if (A[going_left] * A[going_left] < A[going_right] * A[going_right])
        {
            s.push_back(A[going_left] * A[going_left]);
            --going_left;
        }
        else
        {
            s.push_back(A[going_right] * A[going_right]);
            ++going_right;
        }
    }

    // Clean up the rest of the calculations
    while (going_left >= 0)
    {
        s.push_back(A[going_left] * A[going_left]);
        --going_left;
    }

    while (going_right < A.size())
    {
        s.push_back(A[going_right] * A[going_right]);
        ++going_right;
    }

    return s;
}
