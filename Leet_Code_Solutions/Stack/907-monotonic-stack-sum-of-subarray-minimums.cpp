#define ll long long int

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();

        vector<ll> left(n, -1);
        vector<ll> right(n, n);

        // Using non decreasing stack #Monotonic Stack.
        deque<ll> dq;
        for (int i = 0; i < n; i++)
        {
            ll curr = arr[i];
            while (!dq.empty() && arr[dq.back()] >= curr)
            {
                dq.pop_back();
            }
            if (!dq.empty())
            {
                left[i] = dq.back();
            }
            dq.push_back(i);
        }

        dq.clear();

        for (int i = n - 1; i >= 0; i--)
        {
            ll curr = arr[i];
            while (!dq.empty() && curr < arr[dq.back()])
            {
                dq.pop_back();
            }

            if (!dq.empty())
            {
                right[i] = dq.back();
            }

            dq.push_back(i);
        }

        ll mod = 1e9 + 7;

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = (ans + ((ll)(i - left[i]) * (ll)(right[i] - i) % mod * arr[i] % mod)) % mod;
        }

        return ans;
    }
};