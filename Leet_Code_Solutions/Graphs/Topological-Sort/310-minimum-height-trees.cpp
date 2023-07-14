class Solution
{
public:
    int dfs(int root, vector<vector<int>> &graph, vector<bool> &visited)
    {
        if (visited[root])
        {
            return 0;
        }

        int height = 0;
        visited[root] = true;

        for (auto neighbour : graph[root])
        {
            height = max(height, 1 + dfs(neighbour, graph, visited));
        }

        return height;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // Using Similar Idea like Topological Sorting.
        // Creating the order of Objects based on their Dependencies.

        if (n == 1)
            return (vector<int>{0});

        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }

        // Queue holding our leaf nodes.
        queue<int> q;

        // Push all the nodes with inDegree 1.

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 1)
            {
                q.push(i);
                inDegree[i]--;
            }
        }

        // MHT root nodes.
        vector<int> res;

        while (n > 2)
        {
            n -= q.size();

            int s = q.size();
            while (s--)
            {
                int node = q.front();
                q.pop();

                for (auto v : graph[node])
                {
                    inDegree[v]--;
                    if (inDegree[v] == 1)
                    {
                        q.push(v);
                    }
                }
            }
        }

        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }

        return res;

        // while(!q.empty()){
        //     int n = q.size();

        //     res.clear(); // clear the root nodes.

        //     while(n--){
        //         int node = q.front();
        //         q.pop();

        //         // add the current node into the root node vector.
        //         res.push_back(node);

        //         for(int i = 0;i < graph[node].size();i++){
        //             // I will decrease the In degree of the neighbouring nodes
        //             // as I am removing this node.
        //             inDegree[graph[node][i]]--;
        //             if(inDegree[graph[node][i]] == 1) q.push(graph[node][i]);
        //         }
        //     }
        // }

        // return res; // return root nodes for Mht.

        // Brute Force.
        // Map will store the vector of roots for that particular height of trees.

        // map<int, vector<int>> mp;

        // vector<vector<int>> graph(n);
        // for(auto edge : edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     graph[u].push_back(v);
        //     graph[v].push_back(u);
        // }

        // for(int i = 0;i < n;i++){
        //     vector<bool> visited(n, false);
        //     int height = dfs(i, graph, visited);
        //     mp[height].push_back(i);
        // }

        // vector<int> ans = (*mp.begin()).second;

        // return ans;
    }
};