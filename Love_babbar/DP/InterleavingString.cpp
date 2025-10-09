#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int m,n,N;
    bool solve(int i, int j, string& s1, string& s2, string& s3,vector<vector<int>>&dp){
        int k = i+j;
        if(i == m && j== n && k== N) return true;

        if(k>=N) return false; //it means string components are not used totally.

        if(dp[i][j] != -1){

            return dp[i][j];
        }
        bool result = false;

        if(s1[i] == s3[k]){
            result = solve(i+1,j,s1,s2,s3,dp);
        }
        if(result) return true;

        if(s2[j] == s3[k]){
            result = solve(i,j+1,s1,s2,s3,dp);
        }
         
        return  dp[i][j] =  result;

    } 

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n= s2.length();
        N = s3.length();
        if (m + n != N) return false;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return solve(0,0,s1,s2,s3,dp);
    }
};


/*
3-d 

class Solution {
public:
    int m, n, N;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int k, string &s1, string &s2, string &s3) {
        if (i == m && j == n && k == N) return true;
        if (k >= N) return false;

        if (dp[i][j][k] != -1) return dp[i][j][k];

        bool result = false;

        if (i < m && s1[i] == s3[k]) {
            result = solve(i + 1, j, k + 1, s1, s2, s3);
        }
        if (!result && j < n && s2[j] == s3[k]) {
            result = solve(i, j + 1, k + 1, s1, s2, s3);
        }

        return dp[i][j][k] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        if (m + n != N) return false;

        // build dp as a 3D vector initialized with -1
        dp = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(N + 1, -1)));

        return solve(0, 0, 0, s1, s2, s3);
    }
};
*/