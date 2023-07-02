class Solution {
public:
    // will return the length of the longest chain including the current node.
    int dfs(int currNode, vector<vector<int>>& graph, string &s, int &longestPath){
        // the parameters in the dfs call are : 1) currNode, 2) graph(denoting the child nodes.). 3) string s of labels,
        // 4) length of the longest path with no adjacent characters same.(answer).
        
        // longest and second longest chains starting from currNode (does not count the currNode itself).
        int longestChain = 0, secondLongestChain = 0;
        for(auto child : graph[currNode]){
            // get the number of the nodes present in the longest path in the subtree of the child,
            // including the child.
            int longestChainStartingFromChild = dfs(child, graph, s, longestPath);
            
            // if currNode has the same character as child, then we won't move to the child as the condition
            // given to us constraints us.
            if(s[currNode] == s[child]){
                continue;
            }
            
            // modify the longestChain and secondLongestChain if longestChainStartingFromChild is bigger.
            
            if(longestChainStartingFromChild > longestChain){
                secondLongestChain = longestChain;
                longestChain = longestChainStartingFromChild;
            }
            else if(longestChainStartingFromChild > secondLongestChain){
                secondLongestChain = longestChainStartingFromChild;
            }
        }
        
        // Update the answer.
        longestPath = max(longestPath, 1 + longestChain + secondLongestChain);
        return 1 + longestChain; // This is the longest chain starting from node currNode.
    }
    
    int longestPath(vector<int>& parent, string s) {
        // Creation of Adjacency list.
        // We have to return the length of the longest path such that no two adjacent 
        // characters have same character assigned to them.
        
        // unordered_map<int, vector<int>> graph;
        vector<vector<int>> graph(parent.size());
        for(int i = 1;i < parent.size();i++){
            int par = parent[i];
            int child = i;
            graph[par].push_back(child);
        }
        
        // longestPath variable will contain the answer variable.
        int longestPath = 1;
        // will return the length of the longest chain including the current node.
        // within the dfs we may encounter our desired path in which we have longest chain with not the same
        // adjacent characters.
        dfs(0, graph, s, longestPath);
        return longestPath;
    }
};
