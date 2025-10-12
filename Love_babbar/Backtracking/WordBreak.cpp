#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-break/

// suppose s= "leetcode" and  dic =  ["leet","code","le","et"] then here 4th index will overlap hence memoisation is needed.


class Solution {
    
public:
    unordered_set<string>st;
    int n;
    int t[301];

    bool solve(int idx, string &s){
        if(idx >= n) return true;

        if(t[idx] != -1) return t[idx];

        for(int l=1; l<=n; l++){
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() && solve(idx+l, s)) {
                return t[idx]= true;
            }
        }
        return t[idx]= false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t,-1,sizeof(t));
        for(string &word : wordDict){
            st.insert(word);
        }
        return solve(0,s);
    }
};