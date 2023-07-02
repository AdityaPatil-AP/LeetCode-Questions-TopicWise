// Negative Weights lead to infinite loop. So Dijkstra is implemented on when
// it contains positive weights.

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // Adjacency list already given.
        vector<int> distance(V, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (vector<int> it : adj[node])
            {
                int edgeWeight = it[1];
                int neighbourNode = it[0];

                if (dist + edgeWeight < distance[neighbourNode])
                {
                    distance[neighbourNode] = dist + edgeWeight;
                    pq.push({distance[neighbourNode], neighbourNode});
                }
            }
        }

        return distance;
    }
};