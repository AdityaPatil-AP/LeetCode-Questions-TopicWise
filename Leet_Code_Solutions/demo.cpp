#include <bits/stdc++.h>
using namespace std;

int calculateDiameter(vector<vector<int>> &graph, int startVertex)
{
    int n = graph.size();
    vector<int> distance(n, -1);

    queue<int> q;
    q.push(startVertex);

    distance[startVertex] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    int maxDistance = *max_element(distance.begin(), distance.end());
    return maxDistance;
}

int findGraphDiameter(vector<vector<int>> &graph)
{
    int diameter = 0;
    int n = graph.size();

    for (int startVertex = 0; startVertex < n; startVertex++)
    {
        int maxDistance = calculateDiameter(graph, startVertex);
        diameter = max(diameter, maxDistance);
    }

    return diameter;
}
            
int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);

    return 0;
}