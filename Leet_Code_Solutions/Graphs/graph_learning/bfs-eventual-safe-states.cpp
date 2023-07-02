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

    bool dfsCheck(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited,
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

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        // 1) My Submission
        // We will keep a array to track the terminals.
        // vector<int> terminals(V, 0);
        // vector<int> visited(V, 0);

        // vector<int> ans;
        // for(int i = 0;i < V;i++){
        //     if(!visited[i]){
        //         dfs(i, adj, terminals, visited, ans);
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // return ans;

        // 2) DFS Way
        // vector<int> visited(V, 0);
        // vector<int> pathVisited(V, 0);
        // vector<int> check(V, 0);

        // for(int i = 0;i < V;i++){
        //     if(!visited[i]){
        //         dfsCheck(i, adj, visited, pathVisited, check);
        //     }
        // }

        // vector<int> safeNodes;

        // for(int i = 0;i < V;i++){
        //     if(check[i] == 1) safeNodes.push_back(i);
        // }

        // return safeNodes;

        // 3) BFS + Topological Sort.
        // We are considering the outdegree of every node.
        // Instead if we reverse all the edges then we are concerned with indegree.
        // So Topological Sort can be applied here.
        // Steps :
        // - Reversing all the edges.

        vector<int> adjRev[V];
        int inDegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            // Currently edge, i -> it.
            // But we have to do it->i now.
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        // Using a Simple BFS.
        queue<int> q;

        // find the terminal nodes.
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        // Indegree == 0, states that every path that was heading from them
        // reached the terminal node.

        // In dfs approach, we were checking with the cycle approach, those nodes which were
        // present in the cycle or leading into the cycle their visited and pathvisited were both
        // true(because we directly return in that case without changing the path visited so we don't retrace back).
        // Therefore those were not the safe nodes. We kept another array check to store
        // whether they were safe nodes or not during traversal. In this way we solved using dfs.

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            // Explore the neighbouring the nodes.
            for (auto it : adjRev[node])
            {
                inDegree[it]--;

                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};