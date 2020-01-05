#pragma once

#include <algorithm>
#include <vector>
#include <map>

template <
    typename CharType,
    typename IndexType =
        typename std::vector<std::vector<CharType>>::difference_type>
static constexpr auto
row_is_valid(
    const std::vector<std::vector<CharType>> &sudoku,
    const IndexType &row)
    -> bool
{
    return true;
}

template <
    typename CharType,
    typename IndexType =
        typename std::vector<CharType>::difference_type>
static constexpr auto
col_is_valid(
    const std::vector<std::vector<CharType>> &sudoku,
    const IndexType &row)
    -> bool
{
    return true;
}

template <
    typename CharType,
    typename IndexTypeX =
        typename std::vector<CharType>::difference_type,
    typename IndexTypeY =
        typename std::vector<std::vector<CharType>>::difference_type>
static constexpr auto
box_is_valid(
    const std::vector<std::vector<CharType>> &sudoku,
    const IndexTypeX &x_begin,
    const IndexTypeX &x_end,
    const IndexTypeY &y_begin,
    const IndexTypeY &y_end)
    -> bool
{
    return false;
}

namespace leetcode
{

//  This should really be std::array<CharType, N>
template <typename CharType = char>
static constexpr auto
isValidSudoku(
    const std::vector<std::vector<CharType>> &board)
    -> bool
{
    return false;
}

} // namespace leetcode
