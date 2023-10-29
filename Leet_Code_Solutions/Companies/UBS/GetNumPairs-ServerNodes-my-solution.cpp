#include <bits/stdc++.h>
using namespace std;

vector<int> dist;

void dfs(int node, vector<vector<pair<int, int>>> graph, int distance)
{
    if (dist[node] != -1)
        return;

    dist[node] = distance;

    for (auto next : graph[node])
    {
        dfs(next.first, graph, distance + next.second);
    }

    return;
}

vector<int> getNumPairs(int server_nodes, vector<int> &server_from, vector<int> &server_to, vector<int> &server_weight, int signal_speed)
{
    // Creation of graph.
    vector<vector<pair<int, int>>> graph(server_nodes + 1);
    for (int i = 0; i < server_from.size(); i++)
    {
        graph[server_from[i]].push_back({server_to[i], server_weight[i]});
        graph[server_to[i]].push_back({server_from[i], server_weight[i]});
    }

    vector<int> ans(server_nodes, 0);

    for (int i = 1; i <= server_nodes; i++)
    {
        dist = vector<int>(server_nodes + 1, -1);

        dfs(i, graph, 0);
        int cnt = -1;
        for (int j = 1; j <= server_nodes; j++)
        {
            if (dist[j] % signal_speed == 0)
            {
                cnt++;
            }
        }
        ans[i - 1] = (cnt * (cnt - 1));
    }

    return ans;
}

int main()
{
    vector<int> server_from = {1, 1, 2};
    vector<int> server_to = {2, 3, 4};

    vector<int> server_weight = {2, 5, 3};

    vector<int> ans = getNumPairs(4, server_from, server_to, server_weight, 5);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}