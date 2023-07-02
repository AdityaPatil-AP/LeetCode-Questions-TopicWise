class DisjointSet
{
public:
    vector<int> rank, parent;
    vector<int> size; // unionBySize.

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

        if (ulp_v == ulp_u)
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

        if (ulp_v == ulp_u)
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
    int findCircleNum(vector<vector<int>> adj)
    {
        int v = adj.size();
        DisjointSet ds(v);

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionByRank(i, j);
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < v; i++)
        {
            if (ds.parent[i] == i)
            {
                cnt++;
            }
        }

        return cnt;
    }
};