class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // Using dijkstra's algorithm to find the shortest path.
        // Using the edges creating the adjacency list.
        
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        // Source vertex is 1 and destination vertex is N.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1); // Where the current node is coming from.
        for(int i = 0;i <= n;i++) parent[i] = i;
        
        pq.push({0, 1});
        dist[1] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto curr : graph[node]){
                int edgeWeight = curr.second;
                int adjNode = curr.first;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        int node = n;
        vector<int> path;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        if(node != 1){
            return {-1};
        }
        path.push_back(node);
        reverse(path.begin(), path.end());
        
        return path;
    }
};