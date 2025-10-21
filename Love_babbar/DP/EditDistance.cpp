#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    
    //learn about tabulation method 


public:
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>>&dp){
        if(i == word1.length()){ // i is outside of word1 
            return word2.length()-j;  //this much insert operation is needed if 1 is less than 2.
        }

        if(j== word2.length()) return word1.length()-i; //this much delete operation is needed is 1 is greater than 2

        if(dp[i][j] != -1) return dp[i][j];

        int ans =0;

        if(word1[i] == word2[j]) {
            return solve(word1,word2,i+1,j+1,dp);
        }else{
            //insert , here i is not increased because i not adding any character , i just increase my operation by 1 and next char of word1 which will be compared is pointed by i . Similary in deleted case.

            int insertAns = 1+ solve(word1,word2,i,j+1,dp);
            //delete
            int deleteAns = 1+ solve(word1,word2, i+1,j,dp);
            //replace
            int replaceAns = 1+  solve(word1,word2, i+1,j+1,dp);

            ans = min(insertAns,min( deleteAns, replaceAns));
            
        }
        return dp[i][j] = ans; 
        
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length() ,-1));
        return solve(word1, word2, 0,0,dp);
    }
};