class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        // Goal : maximum number of tasks that can be completed.

        // Important Constraints.
        // workers[j] >= tasks[i], then the task can be completed.

        // Some additional magic pills have been provided to us, this pills increase our strength
        // by some value.

        // Every worker only recieves at most one magic pill.

        // The order of the workers and tasks array doesn't matter to us.
        // Therefore, we can sort them.

        // This algorithm fails.
        // We have to think of something else. Greedy doesn't work here.
        //         sort(tasks.begin(), tasks.end());
        //         sort(workers.begin(), workers.end());

        //         int ans = 0;
        //         int n = tasks.size();
        //         int m = workers.size();
        //         vector<int> workDone(m, 0);
        //         int j = 0; // a pointer for workers array.
        //         int i = 0;
        //         for(i = 0;i < n && j < m;){
        //             if(j < m && workers[j] >= tasks[i]){
        //                 workDone[j] = true;
        //                 i++;
        //                 j++;
        //                 ans++;
        //                 continue;
        //             }
        //             else j++;
        //         }

        //         // Let's use the pills wherever we can.
        //         j = 0;
        //         for(;i < n && j < m;){
        //             if(j < m && !workDone[j] && pills > 0 && (workers[j] + strength) >= tasks[i]){
        //                 i++;
        //                 j++;
        //                 pills--;
        //                 ans++;
        //                 continue;
        //             }
        //             else j++;
        //         }

        //         return ans;

        // Discussion - Binary Search.
        // Implementation.

        // Our answer may lie in the range from (0 - n);

        // There workers and tasks array can be sorted as no such constraints
        // are present which stops it.

        int n = tasks.size();
        int m = workers.size();

        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());

        // The benefit of this is that we can easily choose the first m tasks to be done.

        // Here this also suggest that if we are able to do m tasks, then we have to only check if we can
        // do more, there is no need to check for less than m tasks, this divides our search space.
        // and gives us an idea that binary search can be applied.

        int l = 0, r = min(n, m);
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);

            if (can_do_mid_tasks(mid, workers, tasks, pills, strength))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return ans;
    }

    bool can_do_mid_tasks(int m, vector<int> &workers, vector<int> &tasks, int pills, int strength)
    {

        // Adding the workers to the multiset for effecient accessing and deletion of elements
        multiset<int> ms;
        for (auto it : workers)
        {
            ms.insert(it);
        }

        // If we have to complete m tasks, we will complete the easiest m tasks.

        // In that also we will start from the hardest first, so that big values don't
        // get used up for small tasks.

        for (int i = m - 1; i >= 0; i--)
        {
            // First I will check if i can do this task without the helpe of the pills.
            auto it = ms.lower_bound(tasks[i]);
            if (it == ms.end())
            {
                // Now i will check if i can do it with pills.
                if (pills == 0)
                    return false;
                else
                {
                    auto it1 = ms.lower_bound(tasks[i] - strength);
                    if (it1 == ms.end())
                        return false;
                    else
                    {
                        ms.erase(it1);
                        pills--;
                    }
                }
            }
            else
            {
                ms.erase(it);
            }
        }

        return true;
    }
};