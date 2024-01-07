class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        int n = nums.size();

        // declare a dp array of unordered_map

        vector<unordered_map<long, long>> dp(n + 1);

        // dp[i][diff] will store the no. of subsequence with common difference of diff, till ith index

        long ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                long diff = (long)nums[i] - long(nums[j]);

                // update ans

                ans += dp[j][diff];

                // update dp[i][diff]

                dp[i][diff] += dp[j][diff];

                dp[i][diff]++;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<long, vector<int>> map;

        for (int i = 0; i < n; i++)
        {
            long temp = nums[i];
            if (!map.count(temp))
            {
                map[temp] = vector<int>();
            }

            map[temp].push_back(i);
        }

        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long a = 2L * nums[i] - nums[j];

                if (map.count(a))
                {
                    for (int k : map[a])
                    {
                        if (k < i)
                        {
                            dp[i][j] += dp[k][i] + 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                sum += dp[i][j];
            }
        }
        return sum;
    }
};