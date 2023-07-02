class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>&graph, vector<int> &visited){
        set<int> st;
        for(auto neighbour : graph[node]){
            st.insert(visited[neighbour - 1]);
        }
        for(int i = 1;i <= 4;i++){
            if(st.find(i) == st.end()){
                visited[node - 1] = i;
                break;
            }
        }
        for(auto neighbour : graph[node])
            if(!visited[neighbour - 1])
                dfs(neighbour, graph, visited);
        return;
    }
    
    vector<int> bfs(unordered_map<int, vector<int>> &graph, int n){
        vector<int> node_color(n, 0);
        
        for(int node = 1;node <= n;node++){
            if(node_color[node - 1] == 0){
                queue<int> q;
                q.push(node);
                node_color[node - 1] = 1;
                while(!q.empty()){
                    // Pop the front node.
                    int node = q.front();
                    q.pop();

                    // Assigning colors to the nieghbours.
                    for(auto neighbour : graph[node]){
                        // if neigbour node is uncolored assign next color in lexicographical order.
                        if(node_color[neighbour - 1] == 0){
                            // % will give 0 if the color becomes greater than 4.
                            node_color[neighbour - 1] = max(1, (node_color[node - 1] + 1)%5);
                            q.push(neighbour);
                        }
                        else if(node_color[node - 1] == node_color[neighbour - 1]){
                            node_color[neighbour - 1] = max(1, (node_color[node - 1] + 1) % 5);
                        }
                    }
                }   
            }
        }
        return node_color;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Creation of Adjacency list. 
        // unordered_map<int, vector<int>> graph;
        // for(auto path : paths){
        //     graph[path[0]].push_back(path[1]);
        //     graph[path[1]].push_back(path[0]);
        // }
        // // In the visited array itself will store the type of flower.
        // vector<int> visited(n, 0);
        // // It may happen that it may have more than one connected component. So we call dfs for all the 
        // // vertices of the graph.
        // for(int i = 1;i <= n;i++){
        //     // if not visited then visit the node
        //     if(!visited[i - 1]){
        //         dfs(i, graph, visited);
        //     }
        // }
        
//         return visited;
        
        // Using bfs.
        unordered_map<int, vector<int>> graph;
        for(auto path : paths){
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }
        
        return bfs(graph, n);
    }
};