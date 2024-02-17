#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll compute_hash(const string &s)
{
    const ll p = 31;
    const ll mod = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;

    for (char c : s)
    {
        hash_value = (hash_value + p_pow * (c - 'a' + 1)) % mod;
        p_pow = (p * p_pow) % mod;
    }

    return hash_value;
}

int count_unique_substrings(string const &s)
{
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);

    p_pow[0] = 1;

    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(n + 1, 0);

    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;

    for (int l = 1; l <= n; l++)
    {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++)
        {
            long long curr_h = (h[i + l] - h[i]) % m;
            curr_h = (curr_h * p_pow[n - i - 1]) % m;

            hs.insert(curr_h);
        }

        cnt += hs.size();
    }

    return cnt;
}

int main()
{

    string a = "ababa";
    int cnt = count_unique_substrings(a);
    cout << cnt << endl;
}