class Solution
{
public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        // Calculate the number of bombs that can be detonated.
        int n = bombs.size();

        vector<vector<int>> adjacencyList(n);
        for (int i = 0; i < n; i++)
        {
            double x1 = bombs[i][0];
            double y1 = bombs[i][1];
            double r = bombs[i][2];

            for (int j = 0; j < n; j++)
            {
                double x2 = bombs[j][0];
                double y2 = bombs[j][1];

                double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

                if (dist <= r)
                {
                    adjacencyList[i].push_back(j);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n, false);
            int curr = dfs(i, adjacencyList, visited);
            ans = max(ans, curr);
        }

        return ans;
    }

    int dfs(int node, vector<vector<int>> &adjacencyList, vector<int> &visited)
    {
        visited[node] = true;
        int ans = 1;

        for (int neighbour : adjacencyList[node])
        {
            if (!visited[neighbour])
            {
                ans = ans + dfs(neighbour, adjacencyList, visited);
            }
        }

        return ans;
    }
};