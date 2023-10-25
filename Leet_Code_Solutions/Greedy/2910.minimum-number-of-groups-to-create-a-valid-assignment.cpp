class Solution
{
public:
    int check(int x, vector<int> &arr)
    {
        int n = arr.size();
        int a = x, b = x + 1;

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int w = arr[i];
            int curr = INT_MAX;

            if (w % b == 0)
                curr = min(curr, w / b);
            if (w % a == 0)
                curr = min(curr, w / a);

            if (w % b != 0)
            {
                int y = ceil((1.0 * w) / b);
                if (w / y != a)
                {
                    return -1;
                }
                else
                {
                    curr = min(curr, y);
                }
            }

            res += curr;
        }

        return res;
    }

    int minGroupsForValidAssignment(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<int> arr;

        for (auto it : mp)
        {
            arr.push_back(it.second);
        }

        sort(arr.begin(), arr.end());

        int ans = nums.size();

        for (int i = 1; i <= arr[0]; i++)
        {
            int curr = check(i, arr);
            if (curr != -1)
            {
                ans = min(ans, curr);
            }
        }

        return ans;
    }
};