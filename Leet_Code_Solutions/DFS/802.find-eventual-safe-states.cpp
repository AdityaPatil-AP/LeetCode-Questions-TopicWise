class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inStack)
    {
        // If the current node is already in the stack, we have formed a cycle.
        if (inStack[node])
        {
            return true;
        }
        // If the current node is already visited and is not in Stack as well as it is not
        // previously detected as an unsafe node. Which means this is a safe node.
        if (visited[node])
        {
            return false;
        }

        // Mark the current node as visited and part of the recursion stack.

        visited[node] = true;
        inStack[node] = true;

        for (auto neighbour : adj[node])
        {
            if (dfs(neighbour, adj, visited, inStack))
            {
                return true;
            }
        }

        // Remove the node from the stack.
        inStack[node] = false;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        // Approach 1 : Using Depth First Search.
        // Aim : To find the number of unsafe nodes. Nodes that lead to or form a cycle.
        // Because they will never end on the terminal node.

        // int n = graph.size();

        // visited -> Determines if the node have been explored or not.
        // inStack -> Determines if the current node is in the DFS Recursion Stack.
        // denoting that it is present in our path.
        // inStack -> 1) Either the node is in the DFS Recursion Stack.
        //            2) Or it is a previously detected unsafe node.
        // vector<bool> visited(n), inStack(n);

        // for(int i = 0;i < n;i++){
        //     dfs(i, graph, visited, inStack);
        // }

        // vector<int> safeNodes;

        // for(int i = 0;i < n;i++){
        //     if(!inStack[i]){
        //         safeNodes.push_back(i);
        //     }
        // }

        // return safeNodes;

        // 2) Topological Sort Using Kahn's Algorithm.
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (int i = 0; i < n; i++)
        {
            for (auto node : graph[i])
            {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            safe[node] = true;

            for (auto &neighbour : adj[node])
            {
                // Delete the edge "node -> neighbour".
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++)
        {
            if (safe[i])
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};