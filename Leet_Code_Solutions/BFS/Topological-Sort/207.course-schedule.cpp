class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // here we basically want a DAG for our problem.

        // So if there exists a cycle in this graph then it may create a problem.
        // As one course has a pre-requisite course, if they form cycle then we may not
        // be able to finish those courses.

        // How to check whether our directed graph contains a cycle.

        // We can use Kahn's Algorithm(BFS).

        // Approach 1 : Topological Sort Using Kahn's Algorithm(BFS).
        // Here we can see in order to complete a course, all the prerequisites of that course
        // must be complete. But if a cyclic dependency is present then it is impossible
        // to complete all the courses.

        // -> Using Kahn's Algorithm, we can check if all the courses have inDegree == 0.
        // at the end, then all the courses were completed and there was no cyclic dependency.

        // -> If not return false.

        // vector<vector<int>> graph(numCourses);

        // // Calculation of Indegree using Kahn's Algorithm.
        // vector<int> inDegree(numCourses, 0);
        // for(auto pre : prerequisites){
        //     int a = pre[0];
        //     int b = pre[1];
        //     graph[b].push_back(a);
        //     inDegree[a]++;
        // }

        // // Using queue for BFS.
        // queue<int> q;

        // // Pushing all the nodes with Indegree == 0 into the queue.
        // for(int i = 0;i < numCourses;i++){
        //     if(inDegree[i] == 0){
        //         q.push(i);
        //     }
        // }

        // int cnt = 0;
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();

        //     cnt++; // This course is completed as all it's prerequisites are completed.

        //     for(auto it : graph[node]){
        //         inDegree[it]--;
        //         if(inDegree[it] == 0){
        //             q.push(it);
        //         }
        //     }
        // }

        // // If all the courses are completed return true, or else false.
        // return (cnt == numCourses);

        // vector<vector<int>> graph(numCourses);
        // // Calculation inDegree in Kahn's Algorithm is very important it let's us keep track of
        // // independent nodes(which have incoming nodes == 0).
        // vector<int> inDegree(numCourses, 0);
        // for(auto pre : prerequisites){
        //     int a = pre[0];
        //     int b = pre[1];
        //     graph[b].push_back(a);
        //     inDegree[a]++;
        // }

        // // Queue for bfs.
        // queue<int> q;

        // // We will push all the independent nodes into the queue.
        // for(int i = 0;i < numCourses;i++){
        //     if(inDegree[i] == 0){
        //         q.push(i);
        //     }
        // }

        // int cnt = 0; // number of nodes included in topological sort.

        // // We know that in Topological sort, we get linear ordering of n vertices for a Directed Acyclic
        // // Graph.

        // // while q is not empty().
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();

        //     // this node is added to topological sort, so increment the counter.
        //     cnt++;

        //     for(auto it : graph[node]){
        //         inDegree[it]--;

        //         if(inDegree[it] == 0){
        //             q.push(it);
        //         }
        //     }
        // }

        // if(cnt == numCourses) return true;

        // return false;

        // Using DFS.

        // We would not be able to complete all the courses, if there is a cyclic dependency.
        // Therefore we have to check if there is a cyclic dependency or not.

        // If a graph has a cycle, then the current node should have a back edge to one of
        // it's ancestors.

        // Cases -> 1) If the neighbouring node has not yet been visited, then it's not an
        // ancestor.
        // 2) Otherwise if it is visited it may or may not be an ancestor. If it was present
        // in the DFS Recursion Stack, then this is a back edge and therefore the neighbouring
        // node an ancestor.
        // However, if this neighbouring node is visited earlier, which signifies we have
        // explored that node earlier in a different branch, and it does not form a cycle in
        // the current branch.

        // So two arrays required, 1) To store the visited nodes.
        // 2) To Store the nodes present in the DFS Recursion Stack which indicates the
        // current path we are on.

        vector<vector<int>> adj(numCourses);

        for (auto pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
        }

        // visited -> Determines if the node have been explored or not.
        // inStack -> Determines if the current node is in the DFS Recursion Stack.
        // denoting that it is present in our path.
        // inStack -> 1) Either the node is in the DFS Recursion Stack.
        //            2) Or it is a previously detected unsafe node.
        vector<bool> visited(numCourses);
        vector<bool> inStack(numCourses);

        for (int i = 0; i < numCourses; i++)
        {
            if (dfs(i, adj, visited, inStack))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inStack)
    {
        // If the node is in inStack, we have a cycle.
        if (inStack[node])
        {
            return true;
        }

        // If it is already visited but inStack tells us if it is unsafe or not.
        // Therefore this node is a safe node.
        if (visited[node])
        {
            return false;
        }

        // Mark the current node as visited and in inStack as true.
        visited[node] = true;
        inStack[node] = true;

        for (auto neighbour : adj[node])
        {
            if (dfs(neighbour, adj, visited, inStack))
            {
                return true;
            }
        }

        // Remove the node from the stack.
        inStack[node] = false;
        return false;
    }
};