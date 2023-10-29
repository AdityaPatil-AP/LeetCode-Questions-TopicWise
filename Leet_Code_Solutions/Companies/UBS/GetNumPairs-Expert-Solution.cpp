#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

ll n, fact;
vector<ii> adj[1005];
ll dist[1005];

void dfs(ll node, ll p, ll d = 0)
{
    dist[node] = d;
    for (auto x : adj[node]){
        if(x.first != p){
            dfs(x.first, node, d + x.second);
        }
    }

    return;
}

vector<int> getNumPairs(int server_nodes, vector<int> &server_from, vector<int> &server_to, vector<int> &server_weight, int signal_speed)
{
    n = server_nodes;
    fact = signal_speed;
    for (int i = 0; i < server_from.size(); i++)
    {
        adj[server_from[i]].push_back({server_to[i], server_weight[i]});
        adj[server_to[i]].push_back({server_from[i], server_weight[i]});
    }

    vector<int> answer;

    for(int i = 1;i <= n;i++){
        // call is made in such a way that we have i as current node and 0 as parent.
        dfs(i, 0);
        ll cnt = -1;

        for(int j = 1;j <= n;j++){
            if(dist[j] % fact == 0) cnt++;
        }

        answer.push_back((cnt * (cnt - 1)));
    }

    return answer;
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