#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];

        for(int i=1;i< nums.size();i++){
            //if currSum is less than currElement then it means currSum is -ve and it will decrease overall value hence starting new subarray.
            currSum = max(nums[i],currSum+ nums[i]);
            maxSum = max(currSum,maxSum);
        }

        return maxSum;
    }
};