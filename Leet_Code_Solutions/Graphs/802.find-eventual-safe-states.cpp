class Solution
{
public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited,
                  vector<int> &check)
    {
        // Important : Here we can see that whenever we return to the same node again and
        // form a cycle, we don't change the pathVisited array. Therefore those nodes
        // present in the cycle or connected to the cycle will still be marked as 1.
        // Because we don't backtrack in that case we directly return.
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited.
            if (!visited[it])
            {
                if (dfsCheck(it, adj, visited, pathVisited, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVisited[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> check(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsCheck(i, graph, visited, pathVisited, check);
            }
        }

        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};