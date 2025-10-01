#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& currPath, int node) {
        visited[node] = true;
        currPath[node] = true;

        for (auto &neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(adj, visited, currPath, neighbour)) return true;
            }
            else if (currPath[neighbour]) {
                return true; // cycle detected
            }
        }

        currPath[node] = false; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // build adjacency list
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<bool> visited(V, false);
        vector<bool> currPath(V, false);
        //checking if loop exists form ith node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, currPath, i)) return true;
            }
        }
        return false;
    }
};
