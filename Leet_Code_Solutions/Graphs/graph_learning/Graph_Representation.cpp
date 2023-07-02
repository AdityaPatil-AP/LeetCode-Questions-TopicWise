#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Adjacency Matrix take O(n^2) space.
    // int n, m;
    // cin >> n >> m;
    // int adj[n + 1][m + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }
    // For a Weighted Graph instead of storing 1 we have to
    // store the weight.

    // More efficient way of storing using adjacency list.
    // 1-based graph.
    // So if it is a weighted graph, then we can basically change the
    // data structure slightly and rather than storing int, we will store
    // pair<int, int>.

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<pair<int, int>> adj1[n + 1]; // for weighted graph.
    // Space Complexity for Directed Graph : O(E).
    // Space Complexity for Undirected Graph : O(2 * E).
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Weighted Graph.
    return 0;
}