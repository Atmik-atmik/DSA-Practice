#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/sorted-matrix2333/1

class Solution {
  public:
    vector<vector<int>> sortedMatrix(vector<vector<int>>& mat) {
        // code here
        vector<int> arr;
        
        int n = mat.size();
        
        //add element to array
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back(mat[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        //put sorted element back to mat
        
        int k =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = arr[k++];
                
            }
        }
        
        return mat;
    }
};