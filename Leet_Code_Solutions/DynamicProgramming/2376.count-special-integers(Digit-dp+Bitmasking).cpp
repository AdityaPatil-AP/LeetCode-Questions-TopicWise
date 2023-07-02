#define ll long long int
class Solution
{
public:
    int dp[11][2][1024];

    int countSpecialNumbers(int n)
    {
        // vector<int> num;
        // while(n > 0){
        //     int k = n % 10;
        //     n = n/10;
        //     num.push_back(k);
        // }
        // reverse(num.begin(), num.end());
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));

        // parameters -> index, tight, mask -> to keep track of digits used.
        ll ans = helper(0, true, 0, num);

        return ans;
    }

    int helper(int index, bool tight, int mask, string &num)
    {
        if (index == num.size())
        {
            // to check if either of the digit has been used or not.
            // If yes then it returns 1.
            return (mask != 0);
        }

        if (dp[index][tight][mask] != -1)
        {
            return dp[index][tight][mask];
        }

        int ans = 0;

        int end = tight ? num[index] - '0' : 9;

        for (int i = 0; i <= end; i++)
        {
            if (mask & (1 << i))
                continue;

            bool new_tight = tight ? (i == end) : false;

            int new_mask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));

            ans += helper(index + 1, new_tight, new_mask, num);
        }

        return dp[index][tight][mask] = ans;
    }

    // Good Effort -> But to keep the track of the digits used we have to use a mask.

    //     ll helper(int index, vector<bool> &numberUsed, bool limit, vector<int> &num, bool nonZeroUse){
    //         // As we reached the end, which means we have generated a special integer so return 1.
    //         if(index == (num.size())){
    //             return 1;
    //         }

    //         if(dp[index][limit][nonZeroUse] != -1){
    //             return dp[index][limit][nonZeroUse];
    //         }
    //         ll ans = 0;
    //         int end = limit ? 9 : num[index];

    //         for(int i = 0; i <= end;i++){
    //             bool new_end = limit ? 9 : (i != end);

    //             if(i == 0 && !nonZeroUse){
    //                 ans += helper(index + 1, numberUsed, new_end, num, false);
    //             }

    //             else if(numberUsed[i] == false){
    //                 numberUsed[i] = true;
    //                 ans += helper(index + 1, numberUsed, new_end, num, true);
    //                 numberUsed[i] = false;
    //             }
    //         }

    //         return dp[index][limit][nonZeroUse] = ans;
    //     }
};