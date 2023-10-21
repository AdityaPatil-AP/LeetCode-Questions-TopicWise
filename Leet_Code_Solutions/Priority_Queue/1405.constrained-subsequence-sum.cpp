class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        // I will always choose positive numbers to get the maximum sum.
        // But if in case there is no positive number then we have to choose,
        // smallest negative number.

        // dp[i] -> represents the maximum possible sum of a subsequence that
        // ends at i and includes nums[i].

        // Now the problem was when we had to find the dp[j] where j belonged to [i - k, i - 1]
        // To calculate each state we have to traverse k indices back.
        // For large k, there is a problem, how to solve it. for solving that what
        // we know that we only want the maximum sum of all last k indices.
        // We can use a priority queue. But we can only consider the top of the
        // heap element if it is one of the last k indices otherwise pop it.
        // So we have to store the associated index as well.

        // We consider the top element only if positive otherwise it would decrease our
        // subsequent sums.

        // Keep a answer variable to track of maximum possible sum.

        priority_queue<pair<int, int>> pq;

        pq.push({nums[0], 0});
        int ans = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {

            if (i - pq.top().second > k)
            {
                pq.pop();
            }

            int curr = max(0, pq.top().first) + nums[i];

            ans = max(ans, curr);

            pq.push({curr, i});
        }

        return ans;
    }
};