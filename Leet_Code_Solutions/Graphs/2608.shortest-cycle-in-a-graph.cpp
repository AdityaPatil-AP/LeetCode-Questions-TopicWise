class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        // dfs.
        vector<vector<int>> adjList(n);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int ans = INT_MAX;

        // // Using dfs
        // for(int i = 0;i < n;i++){
        //     vector<int> dist(n, -1);
        //     dist[i] = 0;
        //     dfs(i, -1, adjList, dist, ans);
        // }

        // Using bfs.

        for (int i = 0; i < n; i++)
        {
            bfs(i, adjList, ans, n);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }

    void bfs(int node, vector<vector<int>> &adjList, int &ans, const int &n)
    {

        vector<int> parent(n, -1);
        vector<int> dist(n, -1);

        dist[node] = 0;

        queue<int> q;

        q.push(node);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            // Visiting neighbours.
            for (auto neighbour : adjList[curr])
            {
                if (parent[curr] == neighbour)
                    continue;

                // It's the first we are meeting it.
                if (dist[neighbour] == -1)
                {
                    dist[neighbour] = dist[curr] + 1;
                    parent[neighbour] = curr;
                    q.push(neighbour);
                }
                else
                {
                    ans = min(ans, (dist[curr] + dist[neighbour]) + 1);
                }
            }
        }
    }

    void dfs(int node, int parent, vector<vector<int>> &adjList, vector<int> &dist, int &ans)
    {

        // Visit Neighbours.
        for (auto neighbour : adjList[node])
        {
            if (neighbour == parent)
                continue;

            if (dist[neighbour] == -1)
            {
                dist[neighbour] = dist[node] + 1;
                dfs(neighbour, node, adjList, dist, ans);
            }

            else
            {
                ans = min(ans, abs(dist[node] - dist[neighbour]) + 1);
            }
        }

        return;
    }
};