#include "doctest/doctest.h"

#include "leetcode/problem_22.hpp"
#include "util/generic/set_equality.hpp"

#include <set>

TEST_CASE("problem_22")
{
    const int input = 4;
    std::vector<std::string> expected = {
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
    std::sort(
        std::begin(expected),
        std::end(expected),
        [](const auto &lhs, const auto &rhs) -> bool {
            return std::lexicographical_compare(
                std::cbegin(lhs),
                std::cend(lhs),
                std::cbegin(rhs),
                std::cend(rhs));
        });
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    CHECK(util::generic::set_equality(expected, result));
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
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    CHECK(util::generic::set_equality(expected, result));
}

TEST_CASE("problem_22")
{
    const int input = 2;
    const std::vector<std::string> expected = {
        "()()",
        "(())"};
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    CHECK(util::generic::set_equality(expected, result));
}

TEST_CASE("problem_22")
{
    const int input = 1;
    const std::vector<std::string> expected = {
        "()"};
    const std::vector<std::string> result = leetcode::generateParenthesis(input);
    CHECK(util::generic::set_equality(expected, result));
}
