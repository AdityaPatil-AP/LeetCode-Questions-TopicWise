class Solution
{
public:
    void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &signalRecievedAt, int currNode, int currTime)
    {
        // If the currTime is greater than or equal to the fastest signal recieved.
        // Then no need to iterate for the adjacent nodes.
        if (currTime >= signalRecievedAt[currNode])
        {
            return;
        }

        // Fastest Signal Recieved so far.
        signalRecievedAt[currNode] = currTime;

        // BroadCast the signal to the Adjacent Nodes.
        for (pair<int, int> edge : graph[currNode])
        {
            int travelTime = edge.first;
            int dest = edge.second;

            // currTime + travelTime : when the signal reaches the adjacent node.
            dfs(graph, signalRecievedAt, dest, currTime + travelTime);
        }
        return;
    }

    void bfs(vector<vector<pair<int, int>>> &graph, vector<int> &signalRecievedAt, int k)
    {
        queue<int> q;
        q.push(k);

        // Time for the starting node is 0.
        signalRecievedAt[k] = 0;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            // Broadcast the signal to the adjacent nodes.
            for (pair<int, int> edge : graph[currNode])
            {
                int time = edge.first;
                int neighbourNode = edge.second;

                int arrivalTime = signalRecievedAt[currNode] + time;
                if (signalRecievedAt[neighbourNode] > arrivalTime)
                {
                    // Fastest Signal time for neighbour node so far.
                    signalRecievedAt[neighbourNode] = arrivalTime;
                    q.push(neighbourNode);
                }
            }
        }
    }

    void dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &signalRecievedAt, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        // Time for starting node is 0.
        signalRecievedAt[k] = 0;

        while (!pq.empty())
        {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currNodeTime > signalRecievedAt[currNode])
            {
                continue;
            }

            // BroadCast the signal to adjacent Nodes
            for (pair<int, int> edge : graph[currNode])
            {
                int time = edge.first;
                int neighbourNode = edge.second;

                // Fastest signal time for neighbourNode so far.
                if (signalRecievedAt[neighbourNode] > currNodeTime + time)
                {
                    signalRecievedAt[neighbourNode] = currNodeTime + time;
                    pq.push({signalRecievedAt[neighbourNode], neighbourNode});
                }
            }
        }
        return;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // DFS..
        // Creation of Adjacency list.
        vector<vector<pair<int, int>>> graph(n + 1);

        // Generation of a graph.
        // Remember this is a weighted graph.
        for (int i = 0; i < times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        // Sort the edges connecting to every node.
        for (int i = 1; i <= n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
        }

        vector<int> signalRecievedAt(n + 1, INT_MAX);
        // dfs(graph, signalRecievedAt, k, 0);
        // bfs(graph, signalRecievedAt, k);
        dijkstra(graph, signalRecievedAt, k);

        int ans = INT_MIN;
        for (int node = 1; node <= n; node++)
        {
            ans = max(signalRecievedAt[node], ans);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

// Time and Space Complexity Analysis.