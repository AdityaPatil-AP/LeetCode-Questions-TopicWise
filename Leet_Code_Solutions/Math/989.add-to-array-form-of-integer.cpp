class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> ans;
        int n = num.size() - 1;
        int carry = 0;
        while (n >= 0 || k != 0 || carry)
        {
            int rem = k % 10;
            k /= 10;
            int sum = 0;
            if (n >= 0)
                sum += num[n--];
            sum += rem + carry;
            carry = (sum > 9) ? 1 : 0;
            ans.push_back(sum % 10);
        }
        // if(carry) ans.push_back(1);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};