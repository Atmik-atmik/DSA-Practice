#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
public:
  
    int solve(int index, int remainingWt, vector<int> &val, vector<int> &wt,  vector<vector<int>>&dp) {
        // base cases
        if (index == val.size()) return 0;
        if (remainingWt == 0) return 0;
        
        if(dp[index][remainingWt] != -1) return dp[index][remainingWt]; 

        // choice – take or leave
        int take = 0;
        if (wt[index] <= remainingWt) {
            take = val[index] + solve(index + 1, remainingWt - wt[index], val, wt,dp);
        }

        int leave = solve(index + 1, remainingWt, val, wt,dp);

        return dp[index][remainingWt] = max(take, leave);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>>dp(val.size(), vector<int>(W+1,-1));
        return solve(0, W, val, wt,dp);
    }
};
