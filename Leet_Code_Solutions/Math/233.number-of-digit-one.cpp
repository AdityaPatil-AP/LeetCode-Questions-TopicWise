class Solution
{
public:
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

        long long int cnt = 0;
        long long int num = n;
        for (long long int i = 1; i <= num; i *= 10)
        {
            // for ith place in decimal representation.
            int curri = (num / (10 * i)) * i + min(max(num % (10 * i) - i + 1, (long long)0), (long long)i);
            cnt += curri;
        }

        return cnt;
    }
};