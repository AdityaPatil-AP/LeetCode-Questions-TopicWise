class Solution
{
public:
    int minCost(string colors, vector<int> &c)
    {

        int ans = 0;
        int total = c[0];
        int maxi = c[0];
        for (int i = 1; i < colors.size(); i++)
        {

            if (colors[i] != colors[i - 1])
            {
                ans += (total - maxi);
                total = c[i];
                maxi = c[i];
            }
            else
            {
                total += c[i];
                maxi = max(maxi, c[i]);
            }
        }

        ans += (total - maxi);

        return ans;
        // return helper(0, colors, neededTime);
    }

    // int helper(int i, string &c, vector<int> &nT){
    //     if(i == c.size()){
    //         return 0;
    //     }

    //     if()
    // }
};