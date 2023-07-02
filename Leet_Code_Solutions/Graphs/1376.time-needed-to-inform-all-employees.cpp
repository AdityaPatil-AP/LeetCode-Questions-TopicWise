class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> tree(n);

        for (int i = 0; i < n; i++)
        {
            if (manager[i] == -1)
            {
                continue;
            }
            else
            {
                tree[manager[i]].push_back(i);
            }
        }

        int ans = helper(n, headID, tree, informTime);

        return ans;
    }

    int helper(int n, int headID, vector<vector<int>> &tree, vector<int> &informTime)
    {
        // If they don't have a subordination relationship then we have to return zero.
        if (tree[headID].size() == 0)
        {
            return 0;
        }

        int ans = INT_MIN;
        for (int i = 0; i < tree[headID].size(); i++)
        {
            int curr = informTime[headID] + helper(n, tree[headID][i], tree, informTime);
            ans = max(ans, curr);
        }

        return ans;
    }
};