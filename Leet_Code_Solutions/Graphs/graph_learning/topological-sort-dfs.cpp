class Solution
{
public:
    void dfs(int curr, vector<int> adj[], vector<int> &visited, stack<int> &s)
    {
        visited[curr] = 1;

        // visiting the adjacent nodes.
        for (auto child : adj[curr])
        {
            if (!visited[child])
            {
                dfs(child, adj, visited, s);
            }
        }
        s.push(curr);
        return;
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        stack<int> s;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};