class Solution
{
    typedef pair<int, int> T;

public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        // give indexing to the tasks.
        int n = tasks.size(); // total tasks
        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }
        // sort the tasks on the basis of enqueue time.
        sort(tasks.begin(), tasks.end());

        long long int t = tasks[0][0];
        int i = 0;       // to track the current process.
        vector<int> ans; // to store the correct order of the processes.
        // will store all the tasks that are ready to be processed.
        // priority will be given to the smallest job in the pq.
        priority_queue<T, vector<T>, greater<T>> pq;
        while (i < n || !pq.empty())
        {
            while (i < n && t >= tasks[i][0])
            {
                pq.push(make_pair(tasks[i][1], tasks[i][2]));
                i++;
            }
            if (pq.empty())
            {
                t = tasks[i][0];
            }
            else
            {
                T task = pq.top();
                pq.pop();
                ans.push_back(task.second);
                t += task.first;
            }
        }
        return ans;
    }
};