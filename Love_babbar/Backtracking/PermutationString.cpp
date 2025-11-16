#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution
{
public:
    void solve(int index, vector<string> &ans, string s)
    {
        if (index >= s.length())
        {
            ans.push_back(s);
            return;
        }

        unordered_set<char> used; // to track which chars are already placed at 'index'

        for (int j = index; j < s.length(); j++)
        {
            if (used.count(s[j]))
                continue; // skip duplicates

            used.insert(s[j]);
            swap(s[index], s[j]);
            solve(index + 1, ans, s);
            swap(s[index], s[j]); // backtrack
        }
    }

    vector<string> findPermutation(string &s)
    {
        vector<string> ans;
        solve(0, ans, s);
        sort(ans.begin(), ans.end()); // optional: to get lexicographical order
        return ans;
    }
};
