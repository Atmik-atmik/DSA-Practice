#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) return grid[i][j] == 1 ? 0 : 1;
        if (grid[i][j] == 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int down = 0, right = 0;
        if (i + 1 < m) down = solve(i + 1, j, m, n, grid, dp);
        if (j + 1 < n) right = solve(i, j + 1, m, n, grid, dp);
        
        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (grid[0][0] == 1) return 0; // start blocked
        return solve(0, 0, m, n, grid, dp);
    }
};
