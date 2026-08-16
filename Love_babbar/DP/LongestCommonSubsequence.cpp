#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-common-subsequence/description/

//  tabular method

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0)); //here n+1 becaseu i have to use after last index char comparision ,becaseu every pair index LCS depend on later index. 
        //Here n+1 is size of array where last index no. will be n , similarly for m

        for(int i=n-1; i>=0;i--){
            for(int j = m-1;j>=0; j--){

                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];    
                }else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }
};


//memoisation
class Solution {
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>>&dp){
        if(i== text1.length()) return 0;
        if(j== text2.length()) return 0;

        if(dp[i][j] != 0) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans  = 1 + solve(text1 , text2, i+1, j+1,dp);
        } else{
            ans = max(solve(text1, text2, i, j+1,dp) , solve(text1, text2, i+1, j,dp));
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),0));
        return solve(text1, text2, 0, 0,dp);
    }
};