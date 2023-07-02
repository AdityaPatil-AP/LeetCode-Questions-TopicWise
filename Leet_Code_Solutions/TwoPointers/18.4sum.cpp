#define ll long long int
class Solution
{
public:
    // 2sum + 2 loops. - 2 pointers + array + sorting.
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                ll currtarget = (ll)target - nums[i] - nums[j];
                int low = j + 1, high = n - 1;
                while (low < high)
                {
                    ll sum = nums[low] + nums[high];
                    if (sum == currtarget)
                    {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int currlow = nums[low];
                        int currhigh = nums[high];
                        while (low < high && nums[low] == currlow)
                        {
                            low++;
                        }
                        while (low < high && nums[high] == currhigh)
                        {
                            high--;
                        }
                    }
                    else if (sum > currtarget)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};