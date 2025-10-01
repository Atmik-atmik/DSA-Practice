#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backTrack(int &n,vector<string> &ans,int open, int close, string curr){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open <n){
            backTrack(n,ans, open+1,close, curr+ '(');
        }
        if(close<open){
            backTrack(n,ans,open,close+1, curr+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        backTrack(n, ans, 0,0,curr);
        return ans;
    }
};