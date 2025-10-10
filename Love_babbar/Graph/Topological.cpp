#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    void topo(int node,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,
    stack<int> &st){
        visited[node] = 1;
        
        for(int &neighbour: adj[node]){
            if(!visited[neighbour]){
                topo(neighbour,adj,visited,st);
            }
        }
        
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v= edges[i][1];
            
            adj[u].push_back(v);
        }
        
        unordered_map<int,bool> visited;
        stack<int> st;
        vector<int> result;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topo(i,adj,visited,st);
            }
        }
        
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            result.push_back(temp);
        }
        
        return result;
        
    }
};