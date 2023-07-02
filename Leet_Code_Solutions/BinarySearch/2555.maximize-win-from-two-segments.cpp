#define ll long long int
class Solution
{
public:
    int bestRangeAfter(int start, vector<int> &prizePositions, int k, vector<int> &dp)
    {
        int n = prizePositions.size();
        if (start == n)
            return 0;

        if (dp[start] != -1)
        {
            return dp[start];
        }

        // Either this index may be a part of best Range after start or not.

        // 1) no it's not.
        int result = bestRangeAfter(start + 1, prizePositions, k, dp);

        // 2) yes it is.
        int max_possible = prizePositions[start] + k;
        int end_ind = upper_bound(prizePositions.begin(), prizePositions.end(), max_possible) - prizePositions.begin();

        return dp[start] = max(result, end_ind - start);
    }

    int maximizeWin(vector<int> &prizePositions, int k)
    {

        // Now we have to select two ranges in such a fashion that the
        // number of prizes we get are maximum.

        // Now for the first range we can choose any of the prizePositions index as the starting point.
        // and calculate it's maximum possible ending point.

        // For the Second Range. We do some precomputation.
        // After that we have to choose the bestRangeAfterIndex for index i.
        // This will directly give us bestRangeAfterIndex 'i' in O(1).

        // How to do this.

        int n = prizePositions.size();

        int result = INT_MIN;

        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        bestRangeAfter(0, prizePositions, k, dp);

        // We are checking for every index considering it as the starting index of the first range.
        for (int i = 0; i < n; i++)
        {
            int max_possible = prizePositions[i] + k;
            int end_ind = upper_bound(prizePositions.begin(), prizePositions.end(), max_possible) - prizePositions.begin();
            int first_range_prizes = end_ind - i;
            // We have selected the answer for the first range and computed the answer for second range beforehand.
            result = max(result, first_range_prizes + dp[end_ind]);
        }

        return result;
    }
};