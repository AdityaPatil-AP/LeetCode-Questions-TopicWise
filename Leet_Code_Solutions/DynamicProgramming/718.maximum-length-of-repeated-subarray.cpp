class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // Brute Force.
        // We will decide from which index in nums1 and from which index in nums2
        // we want to start comparing.

        // i, j
        // int n = nums1.size();
        // int m = nums2.size();

        // int ans = 0;
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         int start1 = i;
        //         int start2 = j;
        //         int currans = 0;
        //         for(;start1 < n && start2 < m;start1++, start2++){
        //             if(nums1[start1] == nums2[start2]){
        //                 currans++;
        //             }
        //             else{
        //                 break;
        //             }
        //         }
        //         ans = max(ans, currans);
        //     }
        // }

        // return ans;

        // Optimised.
        // There are only 100 unique numbers.

        // Using dp.
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};