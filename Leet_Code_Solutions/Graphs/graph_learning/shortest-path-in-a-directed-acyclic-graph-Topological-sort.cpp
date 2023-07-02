class Solution
{
public:
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topoSort(v, adj, vis, st);
            }
        }

        st.push(node);

        return;
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // find the topo sort.

        // We need visited array and stack for topo sort using dfs.

        int vis[N] = {0};
        stack<int> st;
        // N + E - time complexity.
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        // Step - Do the distance work.
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        // N + E - Time Complexity
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++)
            if (dist[i] == 1e9)
                dist[i] = -1;

        return dist;
    }
};