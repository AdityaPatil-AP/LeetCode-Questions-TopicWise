class Solution
{
public:
    // count -> will store the number of edges to be flipped.
    int count = 0;
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto connection : connections)
        {
            int a = connection[0];
            int b = connection[1];
            // 1-> denoting an original edge.
            // 0-> denoting an artificial edge.
            adjList[a].push_back({b, 1});
            adjList[b].push_back({a, 0});
        }

        // parameters, current node, parent node of current node to avoid backtracking,
        // and adjList.
        // dfs(0, -1, adjList);

        // Using bfs.
        bfs(0, n, adjList);

        return count;
    }

    void bfs(int node, int n, vector<vector<pair<int, int>>> &adjList)
    {
        queue<int> q;
        vector<int> vis(n, 0);
        vis[node] = 1;
        q.push(0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto [child, sign] : adjList[node])
            {
                if (!vis[child])
                {
                    vis[child] = 1;
                    count += sign;
                    q.push(child);
                }
            }
        }

        return;
    }

    void dfs(int node, int parent, vector<vector<pair<int, int>>> &adjList)
    {
        for (auto [child, sign] : adjList[node])
        {
            if (child != parent)
            {
                // if this is an original edge from parent to root node, then it must be
                // flipped. We increment our count in that case.
                count += sign;
                dfs(child, node, adjList);
            }
        }

        return;
    }
};