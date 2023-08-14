class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n - k];

        priority_queue<int> pq;
        for (auto it : nums)
            pq.push(it);

        int ans = 0;
        int curr = 0;
        while (curr++ < k)
        {
            ans = pq.top();
            pq.pop();
        }

        return ans;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int num: nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        return -heap.top();
    }
};
