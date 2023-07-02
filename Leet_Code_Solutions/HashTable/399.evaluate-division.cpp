class Solution
{
    unordered_map<string, vector<pair<string, double>>> adjList; // To map the given string -> to strings which are directly
    // connected to them with a value. (ai/bi).
    // -> bool array to detect and avoid a loop while traversing so re-visiting of nodes is not allowed.
    unordered_map<string, bool> vis;
    double queryAns;

public:
    // dfs will store the queryAns, as well as return true if -> endNode is reachable.
    // or else false.
    bool dfs(string startNode, string endNode, double runningProduct)
    {
        if (startNode == endNode && adjList.find(startNode) != adjList.end())
        {
            queryAns = runningProduct;
            return true;
        }

        vis[startNode] = true;
        bool tempAns = false;

        for (int i = 0; i < adjList[startNode].size(); i++)
        {
            if (!vis[adjList[startNode][i].first])
            {
                tempAns = dfs(adjList[startNode][i].first, endNode, runningProduct * adjList[startNode][i].second);
                if (tempAns == true)
                {
                    break;
                }
            }
        }

        vis[startNode] = false;

        return tempAns;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        int n = equations.size(), m = queries.size();
        vector<double> ans(m);

        for (int i = 0; i < n; i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1 / values[i]});

            vis[equations[i][0]] = false;
            vis[equations[i][1]] = false;
        }

        for (int i = 0; i < m; i++)
        {
            queryAns = 1;
            bool found = dfs(queries[i][0], queries[i][1], 1);
            if (found)
            {
                ans[i] = queryAns;
            }
            else
            {
                ans[i] = -1;
            }
        }

        return ans;
    }
};