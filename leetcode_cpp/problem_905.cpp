#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> result;
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

    vector<int> sortArrayByParity_modernCPP(vector<int> &A)
    {
        vector<int> result(A);
        std::sort(result.begin, result.end, [](int &a, int &b) {
            return a % 2;
        });
        return result;
    }
};