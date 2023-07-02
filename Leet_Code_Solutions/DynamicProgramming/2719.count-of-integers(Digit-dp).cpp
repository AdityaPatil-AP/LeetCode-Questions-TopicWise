long long int dp[23][200][2];

int mod = 1e9 + 7;

class Solution
{
public:
    // helper function -> will find me the number of integers which are smaller than num and have digit sum between
    // min_sum and max_sum.
    int helper(int index, int curr_sum, bool is_already_smaller, string num, int min_sum, int max_sum)
    {
        if (index == num.size())
        {
            return ((curr_sum >= min_sum && curr_sum <= max_sum) ? 1 : 0);
        }

        if (dp[index][curr_sum][is_already_smaller] != -1)
        {
            return dp[index][curr_sum][is_already_smaller];
        }

        long long int ans = 0;

        int end = is_already_smaller ? 9 : (num[index] - '0');

        for (int i = 0; i <= end; i++)
        {
            bool new_smaller = is_already_smaller ? true : (i != end);

            ans = (ans + helper(index + 1, curr_sum + i, new_smaller, num, min_sum, max_sum)) % mod;
        }

        return dp[index][curr_sum][is_already_smaller] = ans;
    }

    int digit_sum(string num)
    {
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            sum += (num[i] - '0');
        }

        return sum;
    }

    string subtractOne(string num)
    {
        int n = num.size();
        int last_non_zero_index = n - 1;
        while (last_non_zero_index >= 0)
        {
            if (num[last_non_zero_index] > '0')
                break;
            last_non_zero_index--;
        }

        num[last_non_zero_index]--;
        for (int j = last_non_zero_index + 1; j < n; j++)
            num[j] = '9';

        return num;
    }

    int count(string num1, string num2, int min_sum, int max_sum)
    {
        // We will find the number of integers less than num2 which have digit sum between min_sum and max_sum.

        memset(dp, -1, sizeof(dp));
        int ans1 = helper(0, 0, false, num2, min_sum, max_sum);
        memset(dp, -1, sizeof(dp));
        // num1 = subtractOne(num1);
        int ans2 = helper(0, 0, false, num1, min_sum, max_sum);

        if (digit_sum(num1) >= min_sum && digit_sum(num1) <= max_sum)
        {
            ans2--;
        }

        int ans = ((ans1 - ans2) + mod) % mod;

        return ans;
    }
};