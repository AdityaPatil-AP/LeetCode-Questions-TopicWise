class Solution
{
public:
    static bool comp(int &a, int &b)
    {
        if (a % 2 == 1 || b % 2 == 1)
        {
            if (a > b && a & 1 && b & 1)
                return false;
            if ((a & 1) == 0 && b & 1)
                return false;
            return true;
        }
        else if (a < b)
            return true;
        return false;
    }

    // static bool comp(int &num1, int &num2){
    //     if(num1 % 2 == 1 || num2 % 2 == 1){
    //         if(num1 > num2 && num1&1 && num2&1) return false;
    //         if((num1&1) == 0 && num2&1) return false;
    //         return true;
    //     }
    //     else if(num1 < num2) return true;
    //     return false;
    // }

    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        // sort.
        sort(nums.begin(), nums.end(), comp);
        sort(begin(target), end(target), comp);
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] - target[i]) >= 0)
            {
                ans += ((long long)nums[i] - (long long)target[i]) / 2;
            }
        }
        return ans;
    }
};