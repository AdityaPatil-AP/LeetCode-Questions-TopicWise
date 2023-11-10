class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // The elements with indegree == 1 will be the corner elements of the array.
        // Other elements will have indegree of 2.
        int n = adjacentPairs.size();
        map<int, int> mp;

        map<int, vector<int>> graph;
        for(int i = 0;i < n;i++){
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            mp[u]++;
            mp[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> start;
        
        for(auto it : mp){
            if(it.second == 1) start.push_back(it.first);
        }

        vector<int> ans;

        // for(int i = 0;i < 2;i++){
        //     dfs(start[i], -1e6, graph, ans);
        // }

        dfs(start[0], -1e6, graph, ans);

        return ans;
    }

    void dfs(int node, int parent, map<int, vector<int>> &graph, vector<int> &ans){
        ans.push_back(node);

        for(auto next : graph[node]){
            if(next != parent){
                dfs(next, node, graph, ans);
            }
        }

        return;
    }
};
