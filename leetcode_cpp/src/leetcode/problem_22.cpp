#include "doctest/doctest.h"

#include "leetcode/problem_22.hpp"

#include <set>

TEST_CASE("problem_22")
{
    const int input = 4;
    const std::vector<std::string> expected = {
        "(((())))",
        "((()()))",
        "((())())",
        "((()))()",
        "(()(()))",
        "(()()())",
        "(()())()",
        "(())(())",
        "(())()()",
        "()((()))",
        "()(()())",
        "()(())()",
        "()()(())",
        "()()()()"};
    // Need to implement setEquality
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    // CHECK(
    //    std::set(expected.cbegin(), expected.cend()) ==
    //    std::set(result.cbegin(), result.cend()));
}

TEST_CASE("problem_22")
{
    const int input = 3;
    const std::vector<std::string> expected = {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"};
    // Need to implement setEquality
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    // CHECK(
    //    std::set(expected.cbegin(), expected.cend()) ==
    //    std::set(result.cbegin(), result.cend()));
}

TEST_CASE("problem_22")
{
    const int input = 2;
    const std::vector<std::string> expected = {
        "()()",
        "(())"};
    // Need to implement setEquality
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    // CHECK(
    //    std::set(expected.cbegin(), expected.cend()) ==
    //    std::set(result.cbegin(), result.cend()));
}

TEST_CASE("problem_22")
{
    const int input = 1;
    const std::vector<std::string> expected = {
        "()"};
    // Need to implement setEquality
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    // CHECK(
    //    std::set(expected.cbegin(), expected.cend()) ==
    //    std::set(result.cbegin(), result.cend()));
}
