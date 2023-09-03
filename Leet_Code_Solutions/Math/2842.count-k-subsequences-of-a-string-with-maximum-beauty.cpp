class Solution
{
public:
    const int mod = 1e9 + 7;

    int countKSubsequencesWithMaxBeauty(string s, int k)
    {
        // We have to choose top k frequencies. so we priority_queue.
        priority_queue<int> pq;

        vector<int> freq(26, 0);

        for (auto x : s)
        {
            freq[x - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }

        if (pq.size() < k)
        {
            return 0;
        }

        long long ans = 1;

        while (k > 0)
        {
            int countEqual = 0, ele = pq.top();

            while (pq.size() > 0 && pq.top() == ele)
            {
                countEqual++;
                pq.pop();
            }

            if (countEqual <= k)
            {
                k -= countEqual;
                ans *= power(ele, countEqual);
                ans %= mod;
            }
            else
            {
                ans *= power(ele, k);
                ans %= mod;

                ans *= nCr(countEqual, k);
                ans %= mod;
                break;
            }
        }

        return ans;
    }

    long long power(int x, int n)
    {
        if (n == 0)
            return 1;

        long long ans = power(x, n / 2);

        ans *= ans;
        ans %= mod;

        if (n % 2 != 0)
        {
            ans *= x;
            ans %= mod;
        }

        return ans;
    }

    long long fact(int n)
    {
        long long ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans *= i;
            ans %= mod;
        }

        return ans;
    }

    long long nCr(int n, int r)
    {
        long long ans = fact(n);
        long long denominator = (fact(r) * fact(n - r)) % mod;

        return (ans * power(denominator, mod - 2)) % mod;
    }
};