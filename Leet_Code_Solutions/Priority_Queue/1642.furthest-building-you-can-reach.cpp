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
        int ans = 0;
        int n = heights.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (isPossible(mid, heights, bricks, ladders))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }

    bool isPossible(int m, vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int> pq;
        // We have to check if we can reach the mth building.
        for (int i = 1; i <= m; i++)
        {
            if (heights[i - 1] < heights[i])
            {
                pq.push(heights[i] - heights[i - 1]);
            }
        }

        while (!pq.empty() && (ladders > 0))
        {
            ladders--;
            pq.pop();
        }
        // If our priority queue is empty which means we can reach the mth builiding.
        // Because it is containing those buildings which require a ladder or a block.
        // But since every building is now given a ladder, we can easily reach the mth building.
        if (pq.empty())
            return true;

        while (!pq.empty() && (bricks > 0))
        {
            int br = pq.top();
            pq.pop();

            if (bricks >= br)
            {
                bricks -= br;
            }
            else
            {
                return false;
            }
        }

        if (pq.empty())
            return true;

        return false;
    }
};