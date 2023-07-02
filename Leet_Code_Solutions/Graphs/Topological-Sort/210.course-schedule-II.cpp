class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // If there exists a cycle or the answer array is less than numCourses size
        // means we are not able to finish all courses. so we return an empty array.

        // This question is based of Directed Acyclic Graph.
        // We have to return the ordering in order to finish all the courses.

        // We can use the Kahn's Algorithm here, which states that the linear ordering
        // of vertices takes place such that if there exists an edge between u -> v, then
        // u should come before v in that ordering.

        // Using bfs.

        vector<int> ans;

        vector<vector<int>> graph(numCourses);
        // We have to also manage an Indegree for taking into account
        // the current independent nodes. which will come at the start.
        // Those nodes having 0 incoming nodes.
        vector<int> inDegree(numCourses, 0);
        for (auto it : prerequisites)
        {
            int a = it[0];
            int b = it[1];
            graph[b].push_back(a);
            inDegree[a]++;
        }

        // Now push all the nodes with inDegree == 0 in the queue.
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Now let's find the right ordering.
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Add this node to the ordering.
            ans.push_back(node);

            // all the neighbouring nodes, their incoming node will reduced by 1.
            for (auto it : graph[node])
            {
                inDegree[it]--;
                // if the current node is having 0 incoming node, then this node can
                // act as the starting node in the topological sort.
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (ans.size() == numCourses)
            return ans;

        return {};
    }
};