class Solution
{
public:
    void helper(vector<int> &nums, int index, set<vector<int>> &ans, vector<int> seq)
    {
        if (index == nums.size())
        {
            if (seq.size() >= 2)
                ans.insert(seq);
            return;
        }
        // Either we can take it and taking the element according to the condition should be possible.
        if (seq.size() == 0 || nums[index] >= seq.back())
        {
            seq.push_back(nums[index]);
            helper(nums, index + 1, ans, seq);
            seq.pop_back();
        }

        // or we will not take it.
        helper(nums, index + 1, ans, seq);
        return;
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        // Recursion.
        // set<vector<int>> ans;
        // vector<int> seq;
        // helper(nums, 0, ans, seq);
        // return vector(ans.begin(), ans.end());
        // Time Complexity : O((2^n) * n);
        // Space Complexity : O((2^n) * n);

        // Using bitmasks.
        int n = nums.size();
        set<vector<int>> result;
        for (int bitmask = 1; bitmask < (1 << n); bitmask++)
        {
            vector<int> sequence;
            for (int i = 0; i < n; i++)
            {
                // Check the ith bit of the bitmask
                if (((bitmask >> i) & 1) == 1)
                {
                    sequence.push_back(nums[i]);
                }
            }
            if (sequence.size() >= 2)
            {
                // check whether sequence is increasing or not.
                bool isIncreasing = true;
                for (int i = 0; i < sequence.size() - 1; i++)
                {
                    isIncreasing &= (sequence[i] <= sequence[i + 1]);
                }
                if (isIncreasing)
                {
                    result.insert(sequence);
                }
            }
        }
        return vector(result.begin(), result.end());
        // Time Complexity : O((2^n) * n);
        // Space Complexity : O((2^n) * n);
    }
};