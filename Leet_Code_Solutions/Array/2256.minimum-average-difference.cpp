#define ll long long int
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        // Obviously we have to use Prefix Sum..
        int n = nums.size();
        vector<ll> ps(nums.size(), 0);
        ps[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            ps[i] += ps[i - 1] + nums[i];
        }
        ll currmin = 1e16;
        ll index = 0;
        for (int i = 0; i < n; i++)
        {
            ll curr = floor(ps[i] / (i + 1));
            if (i < n - 1)
                curr -= floor((ps[n - 1] - ps[i]) / (n - i - 1));
            curr = abs(curr);
            if (curr < currmin)
            {
                index = i;
                currmin = curr;
            }
        }
        return index;
    }
};