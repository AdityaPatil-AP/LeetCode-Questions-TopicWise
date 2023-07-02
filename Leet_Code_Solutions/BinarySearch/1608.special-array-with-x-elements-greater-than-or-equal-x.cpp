class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        // Time Complexity : O(logn)
        //         int n = nums.size();
        //         sort(nums.begin(), nums.end());
        //         int l = 1, r = nums.size();

        //         if(n <= nums[0]){
        //             return n;
        //         }

        //         while(l < r){
        //             int mid = (l + (r - l)/2);

        //             int check = n - mid;

        //             // check if the current mid is the answer.
        //             if((check - 1) >= 0 && nums[check] >= mid && nums[check - 1] < mid){
        //                 return mid;
        //             }

        //             if(nums[check] >= (mid)){
        //                 l = mid + 1;
        //             }
        //             else{
        //                 r = mid;
        //             }
        //         }
        //         return -1;

        // Using lower bound : Time Complexity : O(n*logn).

        sort(nums.begin(), nums.end());

        for (int i = 1; i <= nums.size(); i++)
        {
            auto it = lower_bound(nums.begin(), nums.end(), i);

            if (distance(it, nums.end()) == i)
            {
                return i;
            }
        }

        return -1;
    }
};