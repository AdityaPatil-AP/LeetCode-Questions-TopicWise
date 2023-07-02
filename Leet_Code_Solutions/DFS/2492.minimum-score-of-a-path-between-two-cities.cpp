class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        // Basically we have to the minimum distance of the connnected component.

        // If 1 and n are in the same connected component then return the minimum distance found.
        // Otherwise return 1e9.

        vector<vector<pair<int, int>>> adjacencyList(n + 1);
        for (auto road : roads)
        {
            int a = road[0];
            int b = road[1];
            int distance = road[2];
            adjacencyList[a].push_back({b, distance});
            adjacencyList[b].push_back({a, distance});
        }

        int minDist = 1e9;
        vector<int> visited(n + 1, 0);

        // Using bfs.
        queue<int> q;

        int ans = INT_MAX;
        q.push(1);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            visited[curr] = 1;

            for (auto neighbour : adjacencyList[curr])
            {
                int dest = neighbour.first;
                int dis = neighbour.second;

                ans = min(ans, dis);

                if (!visited[dest])
                {
                    q.push(dest);
                }
            }
        }

        return ans;

        //         dfs(1, adjacencyList, minDist, visited);

        //         return minDist;
    }

    void dfs(int start, vector<vector<pair<int, int>>> &adjacencyList, int &minDist, vector<int> &visited)
    {

        visited[start] = 1;

        for (auto neighbours : adjacencyList[start])
        {
            int neighbour = neighbours.first;
            int distance = neighbours.second;
            minDist = min(minDist, distance);

            if (!visited[neighbour])
            {
                dfs(neighbour, adjacencyList, minDist, visited);
            }
        }

        return;
    }
};