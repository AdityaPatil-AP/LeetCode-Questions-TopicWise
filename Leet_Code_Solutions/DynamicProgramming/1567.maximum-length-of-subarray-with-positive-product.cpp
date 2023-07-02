class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int ans = 0;

        int n = nums.size();

        int poslength = 0;
        int neglength = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                poslength = 0;
                neglength = 0;
            }
            else if (nums[i] > 0)
            {
                poslength = poslength + 1;
                if (neglength)
                    neglength = neglength + 1;
                ans = max(ans, poslength);
            }
            else
            {
                int prevposlength = poslength, prevneglength = neglength;
                poslength = prevneglength ? prevneglength + 1 : 0;
                neglength = prevposlength ? prevposlength + 1 : 1;
                ans = max(ans, poslength);
            }
        }

        return ans;
    }
};