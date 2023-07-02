class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        // Using Priority Queue.
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long ans = 0;
        int cnt = 0, i = 0, j = costs.size() - 1;
        while (cnt < k)
        {
            while (pq1.size() < candidates && i <= j)
                pq1.push(costs[i++]);
            while (pq2.size() < candidates && j >= i)
                pq2.push(costs[j--]);

            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (a <= b)
            {
                ans += a;
                pq1.pop();
            }
            else
            {
                ans += b;
                pq2.pop();
            }
            cnt++;
        }
        return ans;

        //         // Check in whole array.
        //         long long ans = 0;
        //         map<int, int> mp;
        //         if(2 * candidates > costs.size()){
        //             for(int i = 0;i < costs.size();i++){
        //                 mp[costs[i]]++;
        //             }
        //             for(auto it : mp){
        //                 while(k > 0 && it.second > 0){
        //                     ans += it.first;
        //                     it.second--;
        //                     k--;
        //                 }
        //             }
        //         }
        //         else{
        //             // check at specific locations.
        //             map<int, int> mp1;
        //             map<int, int> mp2;
        //             int i = 0, j = costs.size() - 1;
        //             for(int  = 0;i < candidates;i++){
        //                 mp1[costs[i]]++;
        //             }
        //             for(int i = costs.size() - 1;i > costs.size() - candidates;i--){
        //                 mp2[costs[i]]++;
        //             }
        //         }

        //         return ans;
    }
};