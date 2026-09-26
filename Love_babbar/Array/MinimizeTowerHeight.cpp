#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        
        sort(arr.begin(), arr.end());
        //if k is added to all or subtracted(if not negative)
        
        int ans = arr[n-1]- arr[0];
        
        
        //check other possibility by splitting
        for(int i=1; i<n;i++){
            if(arr[i]-k <0) continue;
            
            int smallest = min(arr[0] + k , arr[i]-k);
            int largest = max(arr[i-1]+ k, arr[n-1] -k);
            
            ans = min(ans, largest- smallest);
        }
        
        return ans;
    }
};