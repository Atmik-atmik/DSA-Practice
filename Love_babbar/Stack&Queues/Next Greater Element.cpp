#include <bits/stdc++.h>
using namespace std;

// http://geeksforgeeks.org/problems/next-larger-element-1587115620/1


class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--){

            // Remove elements smaller than or equal to current element
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }

            // If stack is empty, no greater element exists
            if(st.empty()){
                ans[i] = -1;
            } 
            else {
                ans[i] = st.top();
            }

            // Current element can be the answer for elements on left
            st.push(arr[i]);
        }

        return ans;
    }
};