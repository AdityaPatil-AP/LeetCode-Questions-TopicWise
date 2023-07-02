class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        // Linear Traversal.
        //         int cnt = 0;

        //         int n = grid.size();
        //         int m = grid[0].size();

        //         int rowIndex = 0;

        //         for(int i = n - 1;i >= 0;i--){
        //             while(rowIndex < m && grid[i][rowIndex] >= 0){
        //                 rowIndex++;
        //             }
        //             cnt += (m - rowIndex);
        //         }

        //         return cnt;

        // Binary Search.
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            cnt += count(grid[i]);
        }

        return cnt;
    }

    int count(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + (r - l) / 2);

            if (nums[mid] >= 0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return (n - r);
    }
};