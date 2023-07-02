class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        // Binary Search for the value.

        //         int ans = INT_MAX;
        //         int l = 0, r = 1e9;

        //         while(l <= r){
        //             int mid = (l + (r - l)/2);

        //             if(isPossible(mid, nums)){
        //                 ans = mid;
        //                 r = mid - 1;
        //             }
        //             else{
        //                 l = mid + 1;
        //             }
        //         }

        //         return ans;

        // Prefix-Sum + Greedy
        long long answer = 0, prefixSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            prefixSum += nums[i];
            answer = max(answer, (long long)ceil((double)prefixSum / (i + 1)));
        }

        return answer;
    }

    bool isPossible(int num, vector<int> &nums)
    {
        int n = nums.size();
        long long change = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (((long long)nums[i] + change) - num > 0)
            {
                change = ((long long)nums[i] + change) - num;
            }
            else
            {
                change = 0;
            }
        }

        if (((long long)nums[0] + change) > num)
        {
            return false;
        }
        return true;
    }
};