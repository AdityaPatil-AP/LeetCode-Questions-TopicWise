class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // sort(nums.begin(), nums.end());

        // return nums[nums.size() - k];

        priority_queue<int> pq(nums.begin(), nums.end());

        while (k - 1 > 0)
        {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};
