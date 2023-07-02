class Solution
{
public:
    int minimumLines(vector<vector<int>> &sp)
    {
        if (sp.size() == 1)
        {
            return 0;
        }
        sort(sp.begin(), sp.end());
        // Don't Use division while using slope alert!!
        // int x1 = stockPrices[0][0];
        // int y1 = stockPrices[0][1];
        // int x2 = stockPrices[1][0];
        // int y2 = stockPrices[1][1];
        // int ans = 0;
        // long double m1 = (double)(y1 - y2)/(x1 - x2);
        // for(int i = 2; i < stockPrices.size(); i++){
        //     int x3 = stockPrices[i][0];
        //     int y3 = stockPrices[i][1];
        //     int x4 = stockPrices[i-1][0];
        //     int y4 = stockPrices[i-1][1];
        //     double m2 = (long double)(y4 - y3)/(x4 - x3);
        //     // System.out.println(m1+" "+m2);
        //     if(m1 == m2){
        //         continue;
        //     }else{
        //         ans++;
        //         m1 = m2;
        //     }
        // }

        int dx = INT_MIN, dy = INT_MIN;
        int cnt = 0;

        for (int i = 1; i < sp.size(); i++)
        {
            int dx1 = sp[i][0] - sp[i - 1][0], dy1 = sp[i][1] - sp[i - 1][1];
            int d = gcd(dx1, dy1);
            cnt += ((dx != dx1 / d) || (dy != dy1 / d));
            dx = dx1 / d;
            dy = dy1 / d;
        }
        return cnt;
    }
};