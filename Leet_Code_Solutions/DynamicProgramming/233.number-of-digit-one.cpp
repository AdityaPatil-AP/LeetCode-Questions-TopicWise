class Solution
{
public:
    int dp[10][10][2];

    int helper(int index, int cnt, bool limit, vector<int> &num)
    {
        if (index == num.size())
        {
            return cnt;
        }

        if (dp[index][cnt][limit] != -1)
        {
            return dp[index][cnt][limit];
        }

        int ans = 0;

        int end = limit ? 9 : num[index];

        for (int i = 0; i <= end; i++)
        {
            bool new_end = limit ? 9 : (i != end);
            int curr;
            if (i == 1)
            {
                curr = helper(index + 1, cnt + 1, new_end, num);
            }
            else
            {
                curr = helper(index + 1, cnt, new_end, num);
            }
            ans += curr;
        }

        return dp[index][cnt][limit] = ans;
    }

    int countDigitOne(int n)
    {
        // Brute Force.
        // T.C. -> O(n*log10(n)).
        //         int ans = 0;
        //         for(int i = 0;i <= n;i++){
        //             string num = to_string(i);
        //             ans += count(num.begin(), num.end(), '1');
        //         }

        //         return ans;

        // Using Maths
        //         long long int cnt = 0;
        //         long long int num = n;
        //         for(long long int i = 1;i <= num;i *= 10){
        //             // for ith place in decimal representation.
        //             int curri = (num/(10*i)) * i + min(max(num % (10*i) - i + 1, (long long)0), (long long) i);
        //             cnt += curri;
        //         }

        //         return cnt;

        // Using Digit DP.
        vector<int> num;
        while (n > 0)
        {
            int k = n % 10;
            n = n / 10;
            num.push_back(k);
        }
        reverse(num.begin(), num.end());
        memset(dp, -1, sizeof(dp));
        // parameters-> index, count of 1's in the number generated smaller than 1, limit,
        int ans = helper(0, 0, false, num);

        return ans;
    }
};