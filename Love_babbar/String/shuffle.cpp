#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        string s2(n, ' '); // better to initialize with spaces

        for(int i=0; i<n; i++){
            s2[indices[i]] = s[i]; // ← missing semicolon fixed
        }

        return s2;
    }
};
