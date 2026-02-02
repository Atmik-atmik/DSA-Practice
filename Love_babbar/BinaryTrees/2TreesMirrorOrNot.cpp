#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

// User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        //making map which stores child of node in stack
        unordered_map<int, stack<int>> mp;
        
        for(int i=0; i< 2*e; i+= 2){
            mp[A[i]].push(A[i+1]);
        }
        
        //travelling second array and checking if order is reversed or not
        
        for(int i=0; i<2*e; i += 2){
            if(B[i+1] != mp[B[i]].top()) return 0;
            mp[B[i]].pop();
        }
        
        return 1;
    }
};