class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {

        // priority_queue<int, vector<int>, greater<int>> pq1;
        // pq1.push(nums[0]);

        // priority_queue<int, vector<int>, greater<int>> pq2(nums.begin(), nums.end());
        // map<int,int> mp;
        // for(auto i : nums) mp[i]++;
        // mp[nums[0]]--;

        // int ans = 1e9;
        // int n = nums.size();
        // for(int j = 1;j < n - 1;j++){
        //     // I cannot consider this number for my next upcoming numbers priority queue.
        //     mp[nums[j]]--;
        //     int min1 = pq1.top();

        //     while(!pq2.empty() && mp[pq2.top()] == 0){
        //         pq2.pop();
        //     }

        //     int min2 = pq2.top();

        //     if(nums[j] > min1 && nums[j] > min2){
        //         ans = min(ans, min1 + min2 + nums[j]);
        //     }

        //     pq1.push(nums[j]);
        // }

        // return (ans == 1e9) ? -1 : ans;

        // Upsolving.
        // Without using priority_queue.

        int smallestLeft = nums[0];
        vector<int> smallestRight(nums.size(), nums.back());

        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            smallestRight[i] = min(smallestRight[i + 1], nums[i]);
        }

        int ans = 1e9;
        for (int i = 1; i < n - 1; i++)
        {
            if (smallestLeft < nums[i] && nums[i] > smallestRight[i + 1])
            {
                ans = min(ans, nums[i] + smallestRight[i + 1] + smallestLeft);
            }
            smallestLeft = min(smallestLeft, nums[i]);
        }

        return (ans == 1e9 ? -1 : ans);
    }
};