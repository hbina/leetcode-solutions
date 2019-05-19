#include <vector>
#include <cassert>

using std::vector;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {

        if (A.size() == 0)
        {
            return vector<int>{};
        }

        vector<int> s;
        s.reserve(A.size());

        int going_right = 0;

        while (going_right < A.size() && A[going_right] < 0)
        {
            going_right++;
        }

        int going_left = going_right - 1;

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
};

int main()
{
    Solution s;
    vector<int> s1{-4, -1, 0, 3, 10};
    vector<int> s2{};
    s.sortedSquares(s1);
    s.sortedSquares(s2);
}