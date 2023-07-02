
class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &graph)
    {
        visited[node] = 1;

        for (auto child : graph[node])
        {
            if (visited[child] == 0)
            {
                dfs(child, visited, graph);
            }
        }
        return;
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        // Input adjacency matrix but let's do it Adjacency list.
        vector<vector<int>> graph(V);
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[0].size(); j++)
            {
                if (i == j)
                    continue;
                if (adj[i][j] == 1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<int> visited(V, 0);
        int ans = 0;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, visited, graph);
                ans++;
            }
        }

        return ans;
    }
};