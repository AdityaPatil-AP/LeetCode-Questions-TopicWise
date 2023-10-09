class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : flights)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (stops <= k && !q.empty())
        {
            int sz = q.size();
            // Iterate on current level.
            while (sz--)
            {
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbors of popped node.
                for (auto &[neighbour, price] : adj[node])
                {
                    if (price + distance >= dist[neighbour])
                        continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Using Priority Queue.
        // Adjacency List.

        vector<pair<int, int>> adj[n];
        for (auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        // Maintaining a distance vector for storing cost to each city from src.
        vector<int> dist(n, INT_MAX);

        // {stops, {cost, present flight}};

        priority_queue<pair<int, pair<long long, int>>, vector<pair<int, pair<long long, int>>>, greater<pair<int, pair<long long, int>>>> q;

        q.push({0, {0, src}});
        dist[src] = 0;

        long long int ans = LONG_MAX;
        while (q.size())
        {
            int stop = q.top().first;
            long long total = q.top().second.first;
            int from = q.top().second.second;

            q.pop();

            // taking the minimum cost to reach destination in less than or equal to k stops.
            if (stop <= k + 1 && from == dst)
            {
                ans = min(ans, total);
            }

            // No point of checking for the upcoming flights if the stops is greater than k.
            if (stop <= k)
            {
                for (auto it : adj[from])
                {
                    int to = it.first;
                    int cost = it.second;

                    // updating the cost and pushing into priority queue if the previous cost is larger than its previous flight cost + cost of travelling (previous flight ---> present flight).
                    if (dist[to] > total + cost)
                    {
                        dist[to] = total + cost;
                        q.push({stop + 1, {dist[to], to}});
                    }
                }
            }
        }
        return ans == LONG_MAX ? -1 : ans;
    }
};