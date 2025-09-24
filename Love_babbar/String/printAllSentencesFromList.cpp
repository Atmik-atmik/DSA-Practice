#include <bits/stdc++.h>
using namespace std;


// User function Template for C++
class Solution {
  public:
    void solve(int row, vector<vector<string>> &arr, vector<vector<string>> &ans, vector<string> &curr) {
        if (row == arr.size()) {
            ans.push_back(curr);
            return;
        }
    
        for (string &word : arr[row]) {
            curr.push_back(word);
            solve(row + 1, arr, ans, curr); // FIX: row+1 instead of row++
            curr.pop_back();
        }
    }

    vector<vector<string>> sentences(vector<vector<string>> &list) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, list, ans, curr); // FIX: pass list instead of arr
        return ans;
    }
};
