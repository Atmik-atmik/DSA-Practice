#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isPalindrom(string &s,int i, int j,vector<vector<int>>&dp){
        //base case
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i]== s[j]){
            return dp[i][j] =isPalindrom(s,i+1,j-1,dp);
        }

        return dp[i][j] = false;

        // while(i<=j){
        //     if(s[i]!= s[j]) return false;
        //     i++;
        //     j--;
        // }

        // return true;
    }
    string longestPalindrome(string s) {
        int maxLen= INT_MIN;
        int start=0;
        int n = s.length();

        vector<vector<int>>dp(n, vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrom(s,i,j,dp)){
                    if(j-i+1> maxLen){
                        maxLen = j-i+1;
                        start =i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};