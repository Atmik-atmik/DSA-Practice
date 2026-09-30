#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1


class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int cnt = 0;
        
        for(int i=0; i<n-2;i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                if(arr[i] + arr[j] + arr[k] < sum){
                    cnt += k-j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        return cnt;
    }
};