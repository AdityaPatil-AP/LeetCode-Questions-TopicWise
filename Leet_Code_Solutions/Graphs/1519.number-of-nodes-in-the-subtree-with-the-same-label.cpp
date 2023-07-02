class Solution
{
public:
    //
    vector<int> dfs(int node, int parent, unordered_map<int, vector<int>> &graph, vector<int> &ans, string &labels)
    {
        vector<int> nodeCount(26, 0);
        // adding the label of the node itself for it's subtree.
        nodeCount[labels[node] - 'a'] = 1;

        // Traversing all children and compute the count of each label for their subtrees.
        for (auto child : graph[node])
        {
            if (child != parent)
            {
                // If the child is not parent make the dfs call for that children for the count of
                // each label in it's subtree and add it to the node's count.
                vector<int> childCount = dfs(child, node, graph, ans, labels);
                for (int i = 0; i < 26; i++)
                {
                    nodeCount[i] += childCount[i];
                }
            }
        }
        // Adding the count of the node's label in the answer.
        ans[node] = nodeCount[labels[node] - 'a'];
        return nodeCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        // DFS.
        unordered_map<int, vector<int>> graph;
        // Creation of adjacency list using map.
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // Storing count of node's label in thier subtrees.
        vector<int> ans(n, 0);

        // To calculate the count of each label of the parent node subtree.
        // This can be done by calculating the count of each label of every children's subtree.
        dfs(0, -1, graph, ans, labels);

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
//         // BFS.
//         // A tree is undirected, connected graph that has no cycles.
//         // We are going to use map to store the neighbours of every node.
//         unordered_map<int, unordered_set<int>> neighbour;

//         for(auto edge : edges){
//             int u = edge[0];
//             int v= edge[1];
//             neighbour[u].insert(v);
//             neighbour[v].insert(u);
//         }

//         // Now here we cannot use traditional bfs traversal.
//         // Where we start from the src node and traverse level wise to the adjacent nodes.
//         // But here we have to calculate the count of each label(a-z) of the subtrees of it's children first.
//         // In order to compute the answer for the parent node.
//         // So, we have to start building up the answers from the leaf nodes. Key Point - Bottom up.

//         // We require some container to store the count of labels of each node's subtree.
//         vector<vector<int>> countNode(n, vector<int>(26, 0));

//         // How to build a bottom-up answer.
//         // We have to maintain a queue of nodes for sure. which will be storing
//         // the leaf nodes.
//         queue<int> q;

//         // We will store all the leaf nodes as well as mark the count of thier labels to them.
//         for(int i = 0;i < n;i++){
//             // for adding the leaf node into the queue.
//             if(neighbour[i].size() == 1 && i != 0){
//                 q.push(i);
//             }
//             // mark a single count for their own labels.
//             countNode[i][labels[i] - 'a'] = 1;
//         }

//         while(!q.empty()){
//             // dequeue the node
//             int node = q.front();
//             q.pop();

//             // get the parent of that node. The only neighbour it has is the parent.
//             int parent = *neighbour[node].begin();

//             // Now the parent will have to remove this leaf node to avoid traversing back from parent to node.
//             // (Due to this step, we remove all child nodes from a parent, at end parent will only have it's parent in Neighbour map.).
//             neighbour[parent].erase(node);

//             // Add the counts of the curr node in the parent node.
//             for(int i = 0;i < 26;i++){
//                 countNode[parent][i] += countNode[node][i];
//             }

//             // If the parent size is 1 which indicates it has only it's parent in neighbour Map
//             // and parent is not 0. Then the curr node is the last child of the parent so we can insert the parent into
//             // the queue now.

//             if(parent != 0 && neighbour[parent].size() == 1){
//                 q.push(parent);
//             }

//         }

//         // Iterating over all the nodes and storing the answer.
//         vector<int> ans(n, 0);
//         for(int node = 0;node < n;node++){
//             ans[node] = countNode[node][labels[node] - 'a'];
//         }

//         return ans;
//     }
// };
