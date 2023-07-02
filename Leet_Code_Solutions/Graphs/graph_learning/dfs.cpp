class Solution {
  public:
    void dfs(int node, vector<int> &ans, vector<int> &visited, vector<int> adj[], int V){
        visited[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, ans, visited, adj, V);
            }
        }
        return;
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        if(V == 0) return ans;
        vector<int> visited(V, 0);
        dfs(0, ans, visited, adj, V);
        return ans;
    }
};