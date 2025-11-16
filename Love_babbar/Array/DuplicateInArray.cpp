#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> seen(nums.size(),false);


        for(int x: nums){
            if(seen[x]) return x;

            seen[x] = true;
        }
        return -1;
    }
};