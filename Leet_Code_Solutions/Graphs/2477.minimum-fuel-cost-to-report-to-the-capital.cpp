class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &graph, const int &seats, long long &fuel)
    {
        // The node is representative itself.
        int r = 1;

        for (auto child : graph[node])
        {
            if (child != parent)
            {
                r += dfs(child, node, graph, seats, fuel);
            }
        }

        // if the node is not 0. then it need to transport the representatives to the parent node.
        // therefore add the fuel used by them to reach the parent node.
        if (node != 0)
        {
            fuel += ceil((double)r / seats);
        }

        return r;
    }

    void bfs(vector<vector<int>> &graph, vector<int> &degree, long long int &fuel, const int &seats)
    {
        // Number of nodes.
        int n = degree.size();

        // 6) now for bfs we require a queue.
        // What to push in the queue, node values.
        // Push all the nodes with degree[node] == 1.
        // Because they are the leaf nodes.
        queue<int> q;

        for (int i = 1; i < n; i++)
        {
            if (degree[i] == 1)
                q.push(i);
        }

        // 7) We also require a representative array for storing the number of nodes in each node's subtree.
        // We initialise it by 1 because it itself is one representative.
        vector<int> representative(n, 1);

        // 8) start bfs traversal.
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            fuel += ceil((double)representative[node] / seats);

            // For all it's neighbours decrement the degree now because now onwards this node will not be considered.
            // Add it's representatives to it's parent.
            for (auto neighbour : graph[node])
            {
                degree[neighbour]--;
                representative[neighbour] += representative[node];

                // if the degree becomes 1, means that we have added number of representatives in all subtrees
                // of it's children. Node neighbour behaves like a leaf node now. It should not be 0 as it has no parent.
                if (degree[neighbour] == 1 && neighbour != 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        // Creation of adjacency list.
        long long int fuel = 0;
        int n = roads.size();
        // 1) n + 1 -> number of nodes in the tree.
        vector<vector<int>> graph(n + 1);

        // 2) Adjacency list creation.

        // 3) Create a degree array. - It denotes the number of nodes a given node is connected to.

        vector<int> degree(n + 1, 0);
        for (auto road : roads)
        {
            int u = road[0];
            int v = road[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Calling the dfs function with parameters.
        // 1) currnode 2) parent(to keep track of the parent of the currnode so that we don't go in opposite direction)
        // 3) graph 4) seats 5) fuelneeded.

        // Time Complexity : O(n) time - (exploring every node once).
        // O(n) - for initialising the adjacency list.

        // Space Complexity : O(n) space for storing the edges in adjacency list.
        // dfs function will make O(n) recursion calls in worst case scenario.

        // dfs(0, -1, graph, seats, fuel);

        // 4) and 5)  Bfs traversal and passing the parameters correctly.
        bfs(graph, degree, fuel, seats);
        return fuel;
    }
};