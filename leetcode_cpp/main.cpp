#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "solutions/problem_145.hpp"
#include "solutions/problem_88.hpp"
#include "solutions/problem_226.hpp"
#include "solutions/problem_557.hpp"
#include "solutions/problem_589.hpp"
#include "solutions/problem_643.hpp"
#include "solutions/problem_700.hpp"
#include "solutions/problem_888.hpp"
#include "solutions/problem_905.hpp"
#include "solutions/problem_929.hpp"
#include "solutions/problem_938.hpp"
#include "solutions/problem_965.hpp"
#include "solutions/problem_977.hpp"
#include "solutions/problem_1010.hpp"
#include "solutions/problem_1051.hpp"
// Tests here...

TEST_CASE("Problem 1051")
{
    std::vector<int> test1{1, 1, 4, 2, 1, 3};
    CHECK(3 == Solution::heightChecker(test1));
    CHECK(3 == Solution::heightChecker_1(test1));
}

TEST_CASE("Problem 1010")
{
    std::vector<int> test1{30, 20, 150, 100, 40};
    CHECK(3 == Solution::numPairsDivisibleBy60(test1));
};

TEST_CASE("Problem 888")
{
    std::vector<int> test1{1, 1};
    std::vector<int> test2{2, 2};
    CHECK(1 == Solution::fairCandySwap(test1, test2)[0]);
    CHECK(2 == Solution::fairCandySwap(test1, test2)[1]);
};

TEST_CASE("Problem 145")
{
    TreeNode *root = new TreeNode(
        nullptr,
        new TreeNode(
            new TreeNode(
                nullptr,
                nullptr,
                3),
            nullptr,
            2),
        1);

    std::vector<int> result = Solution::postorderTraversal(root);
    std::vector<int> expected = {3, 2, 1};
    CHECK(result.size() == expected.size());
    for (std::size_t iter = 0; iter < result.size(); iter++)
    {
        CHECK(result[iter] == expected[iter]);
    }
};
