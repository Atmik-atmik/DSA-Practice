#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node, int parent) {
        visited[node] = 1;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(adj, visited, neighbour, node)) 
                    return true;
            } 
            else if (neighbour != parent) { // visited neighbor not parent → cycle
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        // Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, i, -1)) 
                    return true;
            }
        }

        return false;
    }
};
