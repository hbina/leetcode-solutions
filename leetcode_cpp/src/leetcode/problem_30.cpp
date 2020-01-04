#include "doctest/doctest.h"

#include "leetcode/problem_30.hpp"
#include "util/generic/set_equality.hpp"

#include <string>
#include <vector>

TEST_CASE("problem_30")
{
    using diff_type = std::vector<std::string>::difference_type;
    const std::string input_1 = "barfoothefoobarman";
    const std::vector<std::string> input_2 = {"foo", "bar"};
    const std::vector<diff_type> expected = {0, 9};
    const std::vector<diff_type> result = leetcode::findSubstring(input_1, input_2);
    // CHECK(util::generic::set_equality(expected, result));
}
