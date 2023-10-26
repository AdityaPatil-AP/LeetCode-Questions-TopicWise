class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        // By sort we are ensuring that we don't traverse the whole array.

        // But to the part where the factor is less than equal sqrt of the current number.
        // Sorting for optimisation.
        sort(arr.begin(), arr.end());
        unordered_set<int> s(arr.begin(), arr.end());

        unordered_map<int, int> dp; // key : Current number as root of the tree.
        // value : number of binary tree that we can make using the tree.

        // Single number in can act as a binary tree with root only.
        for (auto i : arr)
            dp[i] = 1;

        const int mod = 1e9 + 7;

        for (int i : arr)
        {
            for (int j : arr)
            {
                if (j > sqrt(i))
                    break;
                if (i % j == 0 && s.find(i / j) != s.end())
                {
                    long long temp = (long long)dp[j] * dp[i / j];
                    if (i / j == j)
                    {
                        dp[i] = (dp[i] + temp) % mod;
                    }
                    else
                    {
                        dp[i] = (dp[i] + 2 * temp) % mod;
                    }
                }
            }
        }

        int result = 0;
        for (auto &[_, val] : dp)
        {
            result = (result + val) % mod;
        }

        return result;
    }
};