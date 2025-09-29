#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
  bool knows(vector<vector<int>>& mat,int a, int b){
      if(mat[a][b]== 1){
          return true;
      }return false;
  }
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> s;
        int n = mat.size();
        
        for(int i=0;i<mat.size();i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b= s.top();
            s.pop();
            
            if(knows(mat, a,b)){
                s.push(b);
            }else{ // since a doesn't know b hence b can't be celebrity.
                s.push(a);
            }
        }
        int candidate = s.top();
        bool rowCheck = false;
        int zeroCount = 0;
        
        for(int i =0;i<n;i++){
            if(i == candidate) continue;
            if(mat[candidate][i] == 0){
                zeroCount ++;
            }
        }
        
        if(zeroCount == n-1) rowCheck = true;
        
        bool colCheck = false;
        int oneCount = 0;
        
        for(int i=0;i<n;i++){
            if(mat[i][candidate] == 1){
                oneCount++;
            }
        }
        
        if(oneCount == n) colCheck = true;
        
        if(rowCheck== true && colCheck == true) return candidate;
        return -1;
        
    }
};