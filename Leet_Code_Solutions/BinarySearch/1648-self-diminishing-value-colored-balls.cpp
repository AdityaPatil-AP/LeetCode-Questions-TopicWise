class Solution
{
public:
    int mod = 1e9 + 7;
    bool pos(vector<int> &v, int k, int total)
    {
        int curr = 0;
        for (int i = 0; i < v.size(); i++)
        {
            curr += max(0, v[i] - k + 1);
            if (curr >= total)
            {
                return true;
            }
        }
        return false;
    }

    int finder(vector<int> &v, int k, int total)
    {
        long long int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (k + 1 > v[i])
                break;

            ans = ((ans + (1ll * (v[i] + k + 1) * (v[i] - k)) / 2) % mod) % mod;

            total -= (v[i] - k);
        }

        ans = ((ans + (1ll * total * k)) % mod) % mod;

        return ans;
    }

    int maxProfit(vector<int> &v, int orders)
    {
        // Using Binary Search.
        sort(v.begin(), v.end(), greater<int>());

        v.push_back(0);

        int ans = 0;
        int lo = 0;
        int hi = v[0];

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (pos(v, mid, orders))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return finder(v, ans, orders);
    }
};