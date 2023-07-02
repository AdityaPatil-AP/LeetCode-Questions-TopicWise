class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        // Our minimum penalty can be anything between 1 to max(nums);

        // Therefore we can apply linear search and for every value, we check if it possible
        // for that penalty or not.

        // This will give us time limit exceeded.

        // There fore we need some effecient approach. first thing, let's try to think if it is possible
        // for us to apply better searching technique. Binary Search.

        // So here we can see, if for some k it is possible to find the answer then it may be possible
        // for smaller values than k as well.

        int ans = 1;
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (isPossible(mid, nums, maxOperations))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
    }

    bool isPossible(int m, vector<int> &nums, int maxOp)
    {

        int currOp = 0;
        for (auto i : nums)
        {
            currOp += i / m;
            if (i % m == 0)
                currOp--;
            if (currOp > maxOp)
                return false;
        }

        return true;
    }
};