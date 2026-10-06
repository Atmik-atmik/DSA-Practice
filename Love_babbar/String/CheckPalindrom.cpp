#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/palindrome-string0817/1


class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int n = s.length();
        
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-1-i]) return false;
        }
        
        return true;
    }
};