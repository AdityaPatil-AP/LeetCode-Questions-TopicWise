class Solution
{
public:
    vector<vector<int>> dp;

    int dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &coins, int k, int v)
    {
        if (v > 14)
            return 0;
        if (dp[node][v] != -1)
            return dp[node][v];

        int op1 = (coins[node] >> v) - k, op2 = (coins[node] >> (v + 1));

        for (int j : graph[node])
        {
            if (j != parent)
            {
                op1 += dfs(j, node, graph, coins, k, v);
                op2 += dfs(j, node, graph, coins, k, v + 1);
            }
        }

        return dp[node][v] = max(op1, op2);
    }

    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        vector<vector<int>> graph(edges.size() + 1);
        dp = vector(coins.size(), vector<int>(15, -1));
        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return dfs(0, -1, graph, coins, k, 0);
    }
};