class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        // Using Prefix Sum
        // Find Prefix Sum of each row.
        // For each pair of columns, check if submatrices created by them sum
        // to target.

        // int n = matrix.size();
        // int m = matrix[0].size();

        // for(int i = 0;i < n;i++){
        //     for(int j = 1;j < m;j++){
        //         matrix[i][j] += matrix[i][j - 1];
        //     }
        // }

        // int count = 0;
        // for(int c1 = 0;c1 < m;c1++){
        //     for(int c2 = c1;c2 < m;c2++){
        //         unordered_map<int,int> mp;
        //         mp[0] = 1;
        //         long long sum = 0;

        //         for(int row = 0;row < n;row++){
        //             sum += (matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0));
        //             count += mp[sum - target];
        //             mp[sum]++;
        //         }
        //     }
        // }

        // return count;

        // Using Subarray Sum
        int n = matrix.size();
        int m = matrix[0].size();

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> sum(m, 0);

            for (int j = i; j < n; j++)
            {
                for (int col = 0; col < m; col++)
                {
                    sum[col] += matrix[j][col];
                }
                count += subarraySum(sum, target);
            }
        }

        return count;
    }

    int subarraySum(vector<int> nums, int target)
    {
        int curr_sum = 0;
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];

            if (curr_sum == target)
            {
                count++;
            }

            if (mp.find(curr_sum - target) != mp.end())
            {
                count += mp[curr_sum - target];
            }

            mp[curr_sum]++;
        }

        return count;
    }
};