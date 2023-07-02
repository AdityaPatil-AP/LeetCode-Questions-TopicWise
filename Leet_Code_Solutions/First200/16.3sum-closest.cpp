#define ll long long int
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int bestAnswer = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                int curr = nums[i] + nums[low] + nums[high];
                int diff = abs(curr - target);
                if (diff < abs(abs((ll)bestAnswer) - abs((ll)target)))
                {
                    bestAnswer = curr;
                }
                if (curr == target)
                    return target;
                else if (curr < target)
                    low++;
                else
                    high--;
            }
        }
        return bestAnswer;
    }
};