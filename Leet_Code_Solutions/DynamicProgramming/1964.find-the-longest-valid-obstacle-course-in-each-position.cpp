class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        // Traditional LIS.
        // int n = obstacles.size();
        // vector<int> dp(n, 1);

        // for(int i = 1;i < n;i++){
        //     for(int j = i - 1;j >= 0;j--){
        //         if(obstacles[j] <= obstacles[i]){
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //         }
        //     }
        // }

        // return dp;

        // Improved LIS.
        int n = obstacles.size();

        vector<int> ans(n, 1);
        // Whenever we have to reduce the time complexity of searching
        // we have to use some sorted container.
        // We may also need to use some extra space.

        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            int low = 0, high = temp.size() - 1;
            // Using this logic, the low will always point to the next
            // greater element of obstacles[i] or to the end of the array.
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (temp[mid] > obstacles[i])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            if (low == temp.size())
            {
                temp.push_back(obstacles[i]);
            }
            else
            {
                temp[low] = obstacles[i];
            }

            ans[i] = low + 1;
        }

        return ans;
    }
};