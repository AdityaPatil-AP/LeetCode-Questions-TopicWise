// Goal : Our Motive is to find the maximum time for which any data servers message stays alive
// in the server.

// Let's create a tree out of it. It's a wrong idea as it may create a loop and reach back to master server
// in some cases. So what do we do. We will make a graph.

// And then we will find the shortest distance between the master server and
// and the data server. We have to bfs for that.

// Calculate every data Server's active time in the network.
// The one with the highest active time will be the answer. Because for that time the server is still
// passing messages.

class Solution
{
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {

        // Implementation.
        // 1) Creation of Graph.
        int n = patience.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // time array works as visited array.
        vector<int> time(n, -1);
        time[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto child : graph[node])
            {
                // if the node is not visited.
                if (time[child] == -1)
                {
                    time[child] = time[node] + 1;
                    q.push(child);
                }
            }
        }

        // Done computing minimum distance from master server to every data server.

        // Next job. Compute time for which every data server is active in the network.
        // Our aim is to find the time when all the data servers recieve the message and no data is circulated now.
        // The answer will be maximum among all the times which every server takes.

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            // Now we have to first see, how many messages it would have sent.
            // It will continue to send messages, until it receives one.
            // When will it recieve?? at 2 * time[i].
            // From (0 to 2 * time[i] - 1) it will send the messages.
            // Now to calculate the messages sent you can easily divide it by patience[i].

            int messageTravelTime = 2 * time[i];
            int messagesSent = ((2 * time[i] - 1) / patience[i]);
            int lastMessageSent = messagesSent * patience[i];
            int lastMessageRecieved = lastMessageSent + messageTravelTime;

            ans = max(ans, lastMessageRecieved);
        }

        return ans + 1; // Because after the last message was recieved, the next second the network becomes idle.
    }
};