class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &terminals, vector<int> &visited, vector<int> &ans)
    {
        visited[node] = 1;

        // If there are no edges going from it, then the size of
        // vector corresponding to that node in adjacency list would be 0.
        if (adj[node].size() == 0)
        {
            terminals[node] = 1;
        }

        // we will explore it's neighbours to check if the current node is terminal or not.
        bool isSafe = true;
        for (auto it : adj[node])
        {

            if (!visited[it])
            {
                dfs(it, adj, terminals, visited, ans);
            }
            if (terminals[it] == 0)
            {
                isSafe = false;
            }
        }

        // If all the neighbours of the current node are terminals, then it is a
        // safe node.
        if (isSafe)
        {
            ans.push_back(node);
            terminals[node] = 1;
        }

        return;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        // We will keep a array to track the terminals.
        vector<int> terminals(V, 0);
        vector<int> visited(V, 0);

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, terminals, visited, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};