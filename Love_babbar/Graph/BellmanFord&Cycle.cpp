#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 1; i < V; i++)
        {
            for (auto &ed : edges)
            {
                int u = ed[0];
                int v = ed[1];
                int wt = ed[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto &ed : edges)
        {
            int u = ed[0];
            int v = ed[1];
            int wt = ed[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }

        return dist;
    }
};
