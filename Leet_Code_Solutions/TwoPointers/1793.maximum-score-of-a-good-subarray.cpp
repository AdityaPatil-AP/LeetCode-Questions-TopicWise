class Solution
{
public:
    int maximumScore(std::vector<int> &nums, int k)
    {
        // We can do this in O(n^2).
        // But due to the constraints we have to do in O(n).
        // int ans = 0;
        // int n = nums.size();
        // for(int i = 0;i <= k;i++){
        //     int mini = INT_MAX;
        //     for(int m = i;m <= k;m++){
        //         mini = min(mini, nums[m]);
        //     }
        //     for(int j = k;j < n;j++){
        //         mini = min(mini, nums[j]);
        //         ans = max(ans, mini * (j - i + 1));
        //     }
        // }

        // return ans;

        // Using the left and right pointers.
        // We start our subarray at index k.
        int min_val = nums[k];
        int n = nums.size();

        int max_score = min_val; // Maximum score of good subarray.
        int left = k, right = k; // Expansion.
        while (left > 0 || right < n - 1)
        {
            // Decision : Whether to move right or left.
            if (left == 0 || (right < n - 1 && nums[right + 1] > nums[left - 1]))
            {
                right++;
            }
            else
            {
                left--;
            }

            min_val = min(min_val, min(nums[left], nums[right]));
            max_score = max(max_score, min_val * (right - left + 1));
        }

        return max_score;
    }
};