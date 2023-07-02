// Using Disjoint Set.
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent;
    vector<int> size; // for unionBySize

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // storing and using path compression.
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);

        // We don't have n - 1 edges, then it is impossible to change the configuration in such a way that
        // all the components are connected.
        if (connections.size() < (n - 1))
        {
            return -1;
        }

        for (auto connection : connections)
        {
            int a = connection[0];
            int b = connection[1];
            ds.unionBySize(a, b);
        }

        int nC = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                nC++;
        }

        return (nC - 1);
    }
};

// // Using Bfs and dfs.
// class Solution {
//     public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int ans = 0; // will  store the number of connected components.

//         if(connections.size() < (n - 1)){
//             return -1;
//         }

//         vector<vector<int>> adjacencyList(n);

//         for(auto edge : connections){
//             int a = edge[0];
//             int b = edge[1];

//             adjacencyList[a].push_back(b);
//             adjacencyList[b].push_back(a);
//         }

//         vector<int> vis(n, 0);

//         for(int i = 0; i < n;i++){
//             if(!vis[i]){
//                 ans++;
//                 // dfs(i, adjacencyList, vis);
//                 bfs(i, adjacencyList, vis);
//             }
//         }

//         return (ans - 1);
//     }

//     void bfs(int index, vector<vector<int>> &adjacencyList, vector<int> &vis){
//         queue<int> q;
//         q.push(index);
//         vis[index] = 1;

//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();

//             for(auto neighbour : adjacencyList[curr]){
//                 if(!vis[neighbour]){
//                     bfs(neighbour, adjacencyList, vis);
//                 }
//             }
//         }

//         return;
//     }

//     void dfs(int index, vector<vector<int>> &adjacencyList, vector<int> &vis){
//         vis[index] = 1;

//         for(auto neighbour : adjacencyList[index]){
//             if(!vis[neighbour]){
//                 dfs(neighbour, adjacencyList, vis);
//             }
//         }

//         return;
//     }
// };