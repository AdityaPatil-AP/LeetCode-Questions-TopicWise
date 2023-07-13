class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
    }
};