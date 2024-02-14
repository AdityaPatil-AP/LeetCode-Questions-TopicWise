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

vector<vector<int>> group_identical_string(vector<string> const &s)
{
    int n = s.size();
    vector<pair<ll, int>> hashes;
    for (int i = 0; i < n; i++)
    {
        hashes.push_back({compute_hash(s[i]), i});
    }

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || hashes[i] != hashes[i - 1])
        {
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }

    return groups;
}

int main()
{
    string a = "hello";
    string b = "hello";

    if (compute_hash(a) == compute_hash(b))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
}