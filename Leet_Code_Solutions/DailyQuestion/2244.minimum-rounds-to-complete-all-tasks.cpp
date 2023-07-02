class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        int n = tasks.size();
        for (int i = 0; i < n; i++)
        {
            mp[tasks[i]]++;
        }
        int minRounds = 0;
        for (auto task : mp)
        {
            int taskcount = task.second;
            if (taskcount % 3 == 0)
            {
                minRounds += taskcount / 3;
            }
            else if (taskcount % 3 == 1 && taskcount != 1)
            {
                minRounds += (taskcount - 1) / 3 + 1;
            }
            else if (taskcount % 3 == 2)
            {
                minRounds += (taskcount / 3) + 1;
            }
            else
            {
                return -1;
            }
        }
        return minRounds;
    }
};