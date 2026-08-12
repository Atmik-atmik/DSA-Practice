#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/

class Solution
{
public:
    bool isSafe(int row, int col, char val, vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {

            // Check row
            if (board[row][i] == val)
                return false;

            // Check column
            if (board[i][col] == val)
                return false;

            // Check 3 x 3 grid
            if (board[3 * (row / 3) + i / 3]
                     [3 * (col / 3) + i % 3] == val)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> &board)
    {

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {

                // Find empty cell
                if (board[row][col] == '.')
                {

                    // Try 1 to 9
                    for (char val = '1'; val <= '9'; val++)
                    {

                        if (isSafe(row, col, val, board))
                        {

                            // Place value
                            board[row][col] = val;

                            // Recursively solve remaining board
                            if (solve(board))
                            {
                                return true;
                            }

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No value worked for this cell
                    return false;
                }
            }
        }

        // No empty cells -> Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};