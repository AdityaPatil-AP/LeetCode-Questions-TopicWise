class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int inDegree[V] = {0};
        for (auto i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            // node is in your topo sort now,
            // so remove the indegree of it's neighbouring nodes.

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // We have created the adjacency list.
        // We require the topo sort.

        vector<int> topo = topoSort(K, adj);

        string ans;
        for (int i = 0; i < K; i++)
        {
            ans += (topo[i] + 'a');
        }
        return ans;
    }
}