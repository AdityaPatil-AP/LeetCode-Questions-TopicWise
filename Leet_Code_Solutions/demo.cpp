#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

map<pair<int, int>, int> warehouse_weights;
map<pair<int, int>, int> memo; // Memoization

long dfs(int node, int parent, vector<vector<pair<int, int>>> &graph, vector<int> &val, long dist)
{
    cout << node << " " << parent << endl;
    long count = 0;

    for (auto next : graph[node])
    {
        if (next.first != parent)
        {
            int child = next.first;
            int weight = next.second;

            if (dist + weight <= val[child - 1])
            {
                count++;
            }

            count += dfs(child, node, graph, val, dist + weight);
            count += dfs(child, node, graph, val, 0ll);
        }
    }

    return count;
}

long countCompatiblePairs(int warehouse_nodes, const vector<int> &warehouse_from, const vector<int> &warehouse_to, const vector<int> &warehouse_weight, vector<int> &val)
{
    vector<vector<pair<int, int>>> graph(warehouse_nodes + 1);

    for (int i = 0; i < warehouse_nodes; i++)
    {
        int u = warehouse_from[i];
        int v = warehouse_to[i];
        int weight = warehouse_weight[i];

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    long count = 0;

    count = dfs(1, -1, graph, val, 0ll);

    return count;
}

int main()
{
    int warehouse_nodes = 6;
    vector<int> warehouse_from = {1, 6, 1, 1, 4};
    vector<int> warehouse_to = {6, 5, 2, 4, 3};
    vector<int> warehouse_weight = {4, 1, 3, 2, 1};
    vector<int> val = {2, 1, 3, 1, 5, 4};

    long totalCompatiblePairs = countCompatiblePairs(warehouse_nodes, warehouse_from, warehouse_to, warehouse_weight, val);
    cout << "Total Compatible Pairs: " << totalCompatiblePairs << endl;

    return 0;
}
