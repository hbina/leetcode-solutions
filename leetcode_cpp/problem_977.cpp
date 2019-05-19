#include <vector>
#include <cassert>
#include <iostream>

using std::vector;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> s;
        s.reserve(A.size());

        for (int a : A)
        {
            a = a * a;
        }
        return s;
    }

    vector<int> sortedSquares_(vector<int> &A)
    {
        vector<int> s;
        s.reserve(A.size());

        int sign_change_index = 0;

        while (sign_change_index < A.size() && A[sign_change_index] < 0)
        {
            sign_change_index++;
        }

        std::cout << "sign_change_index:" << sign_change_index << std::endl;

        s.push_back(A[sign_change_index]);

        int going_left = sign_change_index - 1;
        int going_right = sign_change_index + 1;

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

    vector<int> result = s.sortedSquares_(s1);

    std::cout << "result:" << std::endl;
    for (const int &a : result)
    {
        std::cout << a << std::endl;
    }
}