#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

int MOD = 1e9 + 7;

long long countValidSequences(int N, int k)
{
    // Base case: With k=1, any pair with distinct numbers works.
    if (k == 1)
    {
        return N * (N - 1);
    }

    // Dynamic programming table to store valid sequence counts for each state (N, k).
    map<pair<int, int>, long long> dp;

    // Iterate over all possible values for the first element in the sequence.
    for (int i = 1; i <= N; ++i)
    {
        // Iterate over all possible remaining values for subsequent elements in the sequence.
        for (int j = 1; j <= N; ++j)
        {
            // Check if the current pair is valid (distinct numbers and unique difference).
            if (i != j && abs(i - j) != abs(j - dp[make_pair(i, k - 1)]))
            {
                // Update the table with the sum of possibilities from previous states.
                dp[make_pair(i, k)] += (dp[make_pair(i, k - 1)] + countValidSequences(N, k - 1)) % MOD;
            }
        }
    }

    // Return the total valid sequence count for the desired state (N, k).
    return dp[make_pair(1, k)];
}

int main()
{
    int N, k;
    cin >> N >> k;

    long long validSequences = countValidSequences(N, k);

    cout << validSequences % MOD << endl;

    return 0;
}