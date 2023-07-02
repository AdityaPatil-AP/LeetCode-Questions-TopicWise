class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int ans = 0; // will  store the number of connected components.

        if (connections.size() < (n - 1))
        {
            return -1;
        }

        vector<vector<int>> adjacencyList(n);

        for (auto edge : connections)
        {
            int a = edge[0];
            int b = edge[1];

            adjacencyList[a].push_back(b);
            adjacencyList[b].push_back(a);
        }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                // dfs(i, adjacencyList, vis);
                bfs(i, adjacencyList, vis);
            }
        }

        return (ans - 1);
    }

    void bfs(int index, vector<vector<int>> &adjacencyList, vector<int> &vis)
    {
        queue<int> q;
        q.push(index);
        vis[index] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neighbour : adjacencyList[curr])
            {
                if (!vis[neighbour])
                {
                    bfs(neighbour, adjacencyList, vis);
                }
            }
        }

        return;
    }

    void dfs(int index, vector<vector<int>> &adjacencyList, vector<int> &vis)
    {
        vis[index] = 1;

        for (auto neighbour : adjacencyList[index])
        {
            if (!vis[neighbour])
            {
                dfs(neighbour, adjacencyList, vis);
            }
        }

        return;
    }
};