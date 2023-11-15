class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans < arr[i])
            {
                ans = ans + 1;
            }
        }

        return ans;
    }
};