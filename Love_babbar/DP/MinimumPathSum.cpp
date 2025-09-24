#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m, n;
    vector<vector<int>> dp; // make dp a member

    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row == m-1 && col == n-1) {
            return grid[row][col]; // base case
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int right = INT_MAX, down = INT_MAX;

        if(col + 1 < n) right = solve(row, col + 1, grid);
        if(row + 1 < m) down = solve(row + 1, col, grid);

        return dp[row][col] = grid[row][col] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1)); // initialize dp

        return solve(0, 0, grid);
    }
};
