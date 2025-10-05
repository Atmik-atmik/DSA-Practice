#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution {
  public:
    bool isSafe(vector<vector<int>> &adj ,vector<int>&color,int node,int col){
        for(int &neighbour: adj[node]){
            if(color[neighbour] == col) return false;
        }
        
        return true;
    }
    
    bool solve( vector<vector<int>> &adj ,vector<int>&color,int node,int &v,int &m){
        
        if(node == v) return true;
        
        for(int i=1;i<=m;i++){
            if(isSafe(adj,color,node,i)){
                color[node] =i;
               if(solve(adj,color,node+1,v,m)) return true;
               color[node] =0;
            }
        }
        
        return false;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        //adj
        
        vector<vector<int>> adj(v);
        
        for(int i=0;i<edges.size();i++){
            
            int u= edges[i][0];
            int v= edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(v,0);
        
        return solve(adj,color,0,v,m);
        
    }
};