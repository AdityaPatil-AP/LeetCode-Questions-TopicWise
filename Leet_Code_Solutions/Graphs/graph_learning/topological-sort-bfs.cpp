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
        // stack<int> s;
        // vector<int> visited(V, 0);

        // for(int i = 0;i < V;i++){
        //     if(!visited[i]){
        //         dfs(i, adj, visited, s);
        //     }
        // }

        // vector<int> ans;
        // while(!s.empty()){
        //     ans.push_back(s.top());
        //     s.pop();
        // }

        // return ans;

        // Using bfs, and using the concept of indegree.

        vector<int> inDegree(V, 0);
        // Indegree has been filled.
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        // Push all the vertices with inDegree == 0 in the queue.
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            // node is in your topo sort
            // so remove it from indegree.

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }
};