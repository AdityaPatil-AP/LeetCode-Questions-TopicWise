class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        // We have to find the number of vertices in every connected component.
        // Then store them in some vector.
        // Use a prefix Sum array.
        // And calculate long long pairs.

        // vector<int> values;

        // creation of adjacency list.
        vector<vector<int>> adjList(n);

        for (auto edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        vector<int> vis(n, 0);

        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                // int count = dfs(i, adjList, vis);
                int count = bfs(i, adjList, vis);
                // values.push_back(count);
            }
        }

        //         vector<int> prefixSum(n);
        //         prefixSum[0] = values[0];
        //         for(int i = 1;i < values.size();i++){
        //             prefixSum[i] = prefixSum[i - 1] + values[i];
        //         }

        //         long long ans = 0;

        //         for(int i = values.size() - 1;i >= 1;i--){
        //             ans = ans + (long long)values[i] * (long long)prefixSum[i - 1];
        //         }

        //         return ans;
    }

    int dfs(int node, vector<vector<int>> &adjList, vector<int> &vis)
    {
        vis[node] = 1;
        int count = 1;
        for (auto neighbour : adjList[node])
        {
            if (!vis[neighbour])
            {
                count += dfs(neighbour, adjList, vis);
            }
        }

        return count;
    }

    int bfs(int node, vector<vector<int>> &adjList, vector<int> &vis)
    {

        queue<int> q;
        q.push(node);
        int count = 1;
        vis[node] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neighbour : adjList[curr])
            {
                if (!vis[neighbour])
                {
                    count++;
                    vis[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return count;
    }
};