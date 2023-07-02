class Solution
{
public:
    void dfs(int start, int distance, vector<vector<pair<int, int>>> &graph, vector<int> &answer, bool isBlue, vector<vector<bool>> &visited)
    {
        // Either visiting this node for the first time.
        // or the node has already been reached here but with a smaller distance then no need for
        // further updations.
        if (answer[start] == -1)
        {
            answer[start] = distance;
        }
        else if (visited[start][isBlue])
        {
            return;
        }

        // If the above cases fail we may get better answers.
        if (answer[start] > distance)
            answer[start] = distance;
        for (auto edge : graph[start])
        {
            int dest = edge.first;
            int color = edge.second;
            if (start == 0)
            {
                if (color == 1 && !visited[start][0])
                {
                    visited[start][0] = 1;
                    dfs(dest, distance + 1, graph, answer, false, visited);
                }
                else if (!visited[start][1])
                {
                    visited[start][1] = 1;
                    dfs(dest, distance + 1, graph, answer, true, visited);
                }
            }
            else
            {
                // if earlier edge was blue and now if we have red edge then we can continue exploring.
                if (isBlue && color == 1 && !visited[start][1])
                {
                    visited[start][0] = 1;
                    dfs(dest, distance + 1, graph, answer, false, visited);
                }
                // else if earlier edge was red and now if we have blue edge then we can continue exploring.
                if (!isBlue && color == 2 && !visited[start][0])
                {
                    visited[start][1] = 1;
                    dfs(dest, distance + 1, graph, answer, true, visited);
                }
            }
        }

        return;
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        // let's create an adjacency list.
        vector<vector<pair<int, int>>> graph(n);

        // Adding the red edges
        for (auto edge : redEdges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back({v, 1});
        }

        // Adding the blue edges.
        for (auto edge : blueEdges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back({v, 2});
        }

        // We need to avoid self edges.
        // And take into consideration parallel edges.
        // Currently let's say path does not exist.
        vector<int> answer(n, -1);

        // vector<vector<bool>> visited(n, vector<bool> (2, false));
        // dfs(0, 0, graph, answer, false, visited);

        // Simple bfs can be done. In dfs loop mai stuck ho sakte.

        // Why bfs?? because one step incrementation is there.

        // One mistake i was doing was that when i have visited for both the colors for the same node I will
        // not visit it again.

        // Now doing it in bfs approach.
        vector<vector<bool>> visited(n, vector<bool>(3, false));

        // what are the components which we should remember while traversing.
        // node, curr distance and the color.

        // I will mark the start location as visited and it's distance as 0.
        visited[0][0] = true;
        visited[0][1] = true;

        answer[0] = 0;

        queue<vector<int>> q;

        q.push({0, 0, -1});

        while (!q.empty())
        {

            auto curr = q.front();
            int node = curr[0];
            int distance = curr[1];
            int prevColor = curr[2];
            q.pop();

            for (auto edge : graph[node])
            {
                int neighbour = edge.first;
                int color = edge.second;
                if (!visited[neighbour][color] && color != prevColor)
                {
                    visited[neighbour][color] = true;
                    q.push({neighbour, distance + 1, color});
                    if (answer[neighbour] == -1)
                        answer[neighbour] = 1 + distance;
                }
            }
        }

        return answer;
    }
};