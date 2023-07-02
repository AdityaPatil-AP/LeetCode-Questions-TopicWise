class Solution
{
public:
    bool dfs(int curr, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited)
    {
        visited[curr] = 1;
        pathVisited[curr] = 1;

        // traverse for adjacent nodes.
        for (auto neighbour : adj[curr])
        {
            // When the node is not visited.
            if (!visited[neighbour])
            {
                if (dfs(neighbour, adj, visited, pathVisited) == true)
                {
                    return true;
                }
            }
            // if the node has been previously visited
            // but it has to visited on the same path again.
            else if (pathVisited[neighbour])
            {
                return true;
            }
        }

        pathVisited[curr] = 0;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here

        // Checking a cycle in Directed Graph using DFS.
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, pathVisited) == true)
                {
                    return true;
                }
            }
        }

        return false;

        // 2) Using Kahn's Algorithm (BFS).
        // vector<int> inDegree(V, 0);
        // for(int i = 0;i < V;i++){
        //     for(auto it : adj[i]){
        //         inDegree[it]++;
        //     }
        // }

        // queue<int> q;

        // // I will push all inDegree == 0 elements which are at the start of topo sort.
        // for(int i = 0;i < V;i++){
        //     if(inDegree[i] == 0){
        //         q.push(i);
        //     }
        // }

        // int cnt = 0;

        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();
        //     cnt++;
        //     for(auto it : adj[node]){
        //         inDegree[it]--;

        //         if(inDegree[it] == 0){
        //             q.push(it);
        //         }
        //     }
        // }

        // if(V == cnt) return false;

        // return true;
    }
};