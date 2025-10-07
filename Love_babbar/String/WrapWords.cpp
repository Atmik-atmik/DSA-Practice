#include <bits/stdc++.h>
using namespace std;

class Solution{
    int solveWordWrap(vector<int> arr, int k){
        int n= arr.size();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int currLen= 0;
            dp[i]=INT_MAX;

            for(int j=i;j++;j<n){
                if(j>i) currLen += 1;//if j is not first word then add space before adding new word

                currLen += arr[j];

                if(currLen>k) break;
                int cost =0;
                if(j==n-1) cost =0;
                else{
                    int extra = k- currLen;

                    cost = extra*extra + dp[j+1];
                }

                dp[i] = min(dp[i],cost);
            }
        }

        return dp[0];
    }
};