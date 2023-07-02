class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int l = 1, r = maxSum;
        int ans = 1;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);

            if (isPossible(n, mid, index, maxSum))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }

    bool isPossible(int n, int mid, int index, int maxSum)
    {
        // Using Maths.
        int val = mid;
        long long sum = 0;
        int after = n - index;

        // Calculations for after the index part.
        if (after - val >= 0)
        {
            sum += ((long long)val * (val + 1)) / 2;
            // remaining are only ones.
            sum += abs(val - after);
        }
        else
        {
            int start = val - after + 1;
            int total = (val - start + 1);
            sum += ((long long)total * (2 * start + (total - 1))) / 2;
        }

        // Calculation for before the index part.
        if ((index + 1) >= val)
        {
            sum += ((long long)val * (val + 1)) / 2;
            // remaining are only ones.
            sum += abs((index + 1) - val);
        }
        else
        {
            int start = val - (index + 1) + 1;
            int total = (val - start + 1);
            sum += ((long long)total * (2 * start + (total - 1))) / 2;
        }

        return ((sum - val) <= maxSum);

        // Creating an array will give tle.
        //         vector<int> arr(n, 1);

        //         arr[index] = mid;

        //         int temp = mid - 1;

        //         for(int i = index + 1;i < n && temp > 1;i++){
        //             arr[i] = temp--;
        //         }

        //         temp = mid - 1;

        //         for(int i = index - 1;i >= 0 && temp > 1;i--){
        //             arr[i] = temp--;
        //         }

        //         long long sum = 0;

        //         for(int i = 0;i < n;i++) sum += arr[i];

        //         return (sum <= maxSum);
    }
};