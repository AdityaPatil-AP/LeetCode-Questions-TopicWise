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

        // priority_queue<pair<int, int>> pq;

        // pq.push({nums[0], 0});
        // int ans = nums[0];
        // int n = nums.size();

        // for(int i = 1;i < n;i++){

        //     if(i - pq.top().second > k){
        //         pq.pop();
        //     }

        //     int curr = max(0, pq.top().first) + nums[i];

        //     ans = max(ans, curr);

        //     pq.push({curr, i});
        // }

        // return ans;

        // Using a Monotonic Queue.
        // Using a Monotonically decreasing queue we are able to find the largest sum
        // from previous k indices in O(1).
        deque<int> deque;
        vector<int> dp(nums.size());

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // Remove the invalid maximums from the start.
            if (!deque.empty() && i - deque.front() > k)
            {
                deque.pop_front();
            }

            dp[i] = (!deque.empty() ? dp[deque.front()] : 0) + nums[i];

            // We are try to maintain a monotonically decreasing queue.
            while (!deque.empty() && dp[deque.back()] < dp[i])
            {
                deque.pop_back();
            }

            // If it is positive then only it makes sense to add it in the queue.
            if (dp[i] > 0)
            {
                deque.push_back(i);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};