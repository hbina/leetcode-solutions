#include "doctest/doctest.h"

#include "leetcode/problem_14.hpp"

TEST_CASE("problem_14")
{
    const std::vector<std::string> input = {"flower", "flow", "flight"};
    const std::string expected = "fl";
    const std::string result = leetcode::longestCommonPrefix(input);
    const std::string result_Iterator = leetcode::longestCommonPrefix_Iterator(
        input.cbegin(),
        input.cend());
    CHECK(expected == result);
    CHECK(expected == result_Iterator);
}

TEST_CASE("problem_14")
{
    const std::vector<std::string> input = {"", ""};
    const std::string expected = "";
    const std::string result = leetcode::longestCommonPrefix(input);
    const std::string result_Iterator = leetcode::longestCommonPrefix_Iterator(
        input.cbegin(),
        input.cend());
    CHECK(expected == result);
    CHECK(expected == result_Iterator);
}

TEST_CASE("problem_14")
{
    const std::vector<std::string> input = {"dog", "racecar", "car"};
    const std::string expected = "";
    const std::string result = leetcode::longestCommonPrefix(input);
    const std::string result_Iterator = leetcode::longestCommonPrefix_Iterator(
        input.cbegin(),
        input.cend());
    CHECK(expected == result);
    CHECK(expected == result_Iterator);
}

TEST_CASE("problem_14")
{
    const std::vector<std::vector<int>> input = {{1, 2, 3, 5}, {1, 2, 3, 4}, {1, 2, 6}};
    const std::vector<int> expected = {1, 2};
    const std::vector<int> result_Iterator = leetcode::longestCommonPrefix_Iterator(
        input.cbegin(),
        input.cend());
    CHECK(expected == result_Iterator);
}
