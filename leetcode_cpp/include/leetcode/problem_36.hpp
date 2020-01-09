#pragma once

#include <algorithm>
#include <vector>
#include <set>

//  TODO    ::  Implement a dispatcher tag for std::array<T,N> which can definitely be made
//              constexpr-able.

template <
    typename CharType = char,
    typename IndexTypeY =
        typename std::vector<std::vector<CharType>>::difference_type,
    typename IndexTypeX =
        typename std::vector<CharType>::difference_type>
static constexpr auto
row_is_valid(
    const std::vector<std::vector<CharType>> &sudoku,
    const IndexTypeY &row_index)
    -> bool
{
    std::set<CharType> set;
    for (IndexTypeX x = 0; x < 9; x++)
    {
        if (sudoku[row_index][x] == '.')
            continue;
        else if (set.find(sudoku[row_index][x]) == std::cend(set))
            set.insert(sudoku[row_index][x]);
        else
            return false;
    }
    return true;
}

template <
    typename CharType = char,
    typename IndexTypeY =
        typename std::vector<std::vector<CharType>>::difference_type,
    typename IndexTypeX =
        typename std::vector<CharType>::difference_type>
static constexpr auto
col_is_valid(
    const std::vector<std::vector<CharType>> &sudoku,
    const IndexTypeX &col_index)
    -> bool
{
    std::set<CharType> set;
    for (IndexTypeX y = 0; y < 9; y++)
    {
        if (sudoku[y][col_index] == '.')
            continue;
        else if (set.find(sudoku[y][col_index]) == std::cend(set))
            set.insert(sudoku[y][col_index]);
        else
            return false;
    }
    return true;
}

template <
    typename CharType = char,
    typename IndexTypeY =
        typename std::vector<std::vector<CharType>>::difference_type,
    typename IndexTypeX =
        typename std::vector<CharType>::difference_type>
static constexpr auto
box_is_valid(
    const std::vector<std::vector<CharType>> &sudoku,
    const IndexTypeX &x_begin,
    const IndexTypeX &x_end,
    const IndexTypeY &y_begin,
    const IndexTypeY &y_end)
    -> bool
{
    std::set<CharType> set;
    for (IndexTypeY y_iter = y_begin; y_iter < y_end; ++y_iter)
    {
        for (IndexTypeX x_iter = x_begin; x_iter < x_end; ++x_iter)
        {
            if (sudoku[y_iter][x_iter] == '.')
                continue;
            else if (set.find(sudoku[y_iter][x_iter]) == std::cend(set))
                set.insert(sudoku[y_iter][x_iter]);
            else
                return false;
        }
    }
    return true;
}

namespace leetcode
{

//  This should really be std::array<CharType, N>
template <
    typename CharType = char,
    typename IndexTypeY =
        typename std::vector<std::vector<CharType>>::difference_type,
    typename IndexTypeX =
        typename std::vector<CharType>::difference_type>
static constexpr auto
isValidSudoku(
    const std::vector<std::vector<CharType>> &board)
    -> bool
{
    for (IndexTypeY y = 0; y < 9; y += 3)
    {
        for (IndexTypeX x = 0; x < 9; x += 3)
        {
            if (!box_is_valid(board, x, x + 3, y, y + 3))
                return false;
        }
    }

    // Row unique
    for (IndexTypeY y = 0; y < 9; y++)
    {
        if (!row_is_valid(board, y))
            return false;
    }

    // Column unique
    for (IndexTypeX x = 0; x < 9; x++)
    {
        if (!col_is_valid(board, x))
            return false;
    }
    return true;
}

} // namespace leetcode
