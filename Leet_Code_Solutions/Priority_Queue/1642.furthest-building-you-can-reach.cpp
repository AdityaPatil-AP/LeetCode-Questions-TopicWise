// class Solution {
// public:

//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         // What we can say is that we have to reach the last building itself.
//         // What we would do, we would the assign ladder to the largest (ladder) amount of values.
//         // and then go till our sum of others doesn't exceed the brick ones.

//         int ans = 0;
//         int n = heights.size();
//         long long sum = 0;
//         // This will store atmost ladder amount of values, which are the largest ladder values.
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i = 1;i < n;i++){
//             if(heights[i - 1] >= heights[i]){
//                 ans = i;
//                 continue;
//             }
//             int diff = heights[i] - heights[i - 1];
//             if(pq.size() < ladders){
//                 pq.push(diff);
//             }
//             else{
//                 if(!pq.empty() && diff > pq.top()){
//                     sum += pq.top();
//                     if(sum > bricks) return ans;
//                     pq.pop();
//                     pq.push(diff);
//                 }
//                 else{
//                     sum += diff;
//                     if(sum > bricks) return ans;
//                 }
//             }
//             // Update the answer every time.
//             ans = i;
//         }

//         return (n - 1);
//     }
// };

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // I cannot use dynamic programming because in variable parameters, bricks value
        // can go as high as 1e9. which is not possible to store.

        // Using some greedy way.
        int n = heights.size();

        priority_queue<int, vector<int>, greater<int>> pq;
        int extra = 0;
        for (int i = 1; i < n; i++)
        {
            int curr = 0;
            if (heights[i] > heights[i - 1])
                curr = heights[i] - heights[i - 1];

            if (pq.size() < ladders)
            {
                pq.push(curr);
            }
            else
            {
                if (!pq.empty() && pq.top() < curr)
                {
                    extra += pq.top();
                    pq.pop();
                    pq.push(curr);
                }
                else
                {
                    extra += curr;
                }

                if (extra > bricks)
                {
                    return i - 1;
                }
            }
        }

        return n - 1;
    }
};