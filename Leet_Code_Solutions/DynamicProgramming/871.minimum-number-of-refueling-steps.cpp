class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        // // dp[i] indicates the farthest distance I can travel with i refueling stops.
        // int n = stations.size();
        // vector<long long> dp(n + 1, 0ll);
        // dp[0] = startFuel;
        // for(int i = 0;i < n;i++){
        //     for(int t = i;t >= 0;t--){
        //         if(dp[t] >= stations[i][0]){
        //             dp[t + 1] = max(dp[t + 1], dp[t] + (long)stations[i][1]);
        //         }
        //     }
        // }

        // for(int i = 0;i <= n;i++){
        //     if(dp[i] >= target) return i;
        // }

        // return -1;

        // // We we run out of fuel before reaching the next station, we will retroactively
        // // fuel up : greedily choosing the largest gas stations first.

        // priority_queue<int> pq;
        // int n = stations.size();
        // int ans = 0, prev = 0;
        // int tank = startFuel; // to keep the track of the current fuel.

        // for(int i = 0;i < n;i++){
        //     int loc = stations[i][0];
        //     int cap = stations[i][1];

        //     tank -= (loc - prev);

        //     // If the tank value is negative for this station which means we must
        //     // have refueled the tank before this station.
        //     while(!pq.empty() && tank < 0){
        //         tank += pq.top();
        //         pq.pop();
        //         ans++;
        //     }

        //     if(tank < 0) return -1; // if still the tank is negative which means we can
        //     // never reach this current station so return negative.

        //     // Here the most important point is don't use the fuel unless it is required.
        //     // Just keep on storing it.
        //     pq.push(cap);

        //     prev = loc;
        // }

        // // Because target is present after the last location.

        // tank -= (target - prev);

        // while(!pq.empty() && tank < 0){
        //     ans++;
        //     tank += pq.top();
        //     pq.pop();
        // }

        // if(tank < 0) return -1;

        // return ans;
    }
};