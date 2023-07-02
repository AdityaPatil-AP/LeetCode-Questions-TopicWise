class Solution
{
public:
    int dp[10][2][2];

    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {

        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        digits.push_back("0");
        sort(digits.begin(), digits.end());
        int ans = helper(0, true, num, digits, false);

        // because 0 is being added to the answer.
        ans--;

        return ans;
    }

    int helper(int index, bool tight, string &num, vector<string> &digits, bool nonZeroUsed)
    {
        if (index == num.size())
        {
            return 1;
        }

        if (dp[index][tight][nonZeroUsed] != -1)
        {
            return dp[index][tight][nonZeroUsed];
        }

        int ans = 0;

        int end = tight ? (num[index] - '0') : 9;

        for (int i = 0; i < digits.size(); i++)
        {
            int currnum = digits[i][0] - '0';
            if (currnum == 0 && !nonZeroUsed)
            {
                ans += helper(index + 1, false, num, digits, false);
            }
            else if (currnum <= end && currnum != 0)
            {
                bool new_tight = tight ? (currnum == end) : false;

                ans += helper(index + 1, new_tight, num, digits, true);
            }
        }

        return dp[index][tight][nonZeroUsed] = ans;
    }
};