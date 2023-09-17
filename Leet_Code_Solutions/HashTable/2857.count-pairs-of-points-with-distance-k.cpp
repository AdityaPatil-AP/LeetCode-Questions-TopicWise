class Solution
{
public:
    int countPairs(vector<vector<int>> &coordinates, int k)
    {
        // Brute Force. O(n^2) appraoch. Using two for loops to iterate for pair of points
        // calculating the distance between them. If it's equal to k, increment answer.

        // But now we have to optimise this solution so that we can do it lower upper bound.

        // int ans = 0;

        // int n = coordinates.size();

        // // It's giving time limit exceeded for one test case.

        // // For that we have to precompute something in order to find the solution.

        // for(int i = 0;i < n;i++){
        //     for(int j = i + 1;j < n;j++){
        //         int x1 = coordinates[i][0];
        //         int y1 = coordinates[i][1];
        //         int x2 = coordinates[j][0];
        //         int y2 = coordinates[j][1];

        //         if(((x1^x2) + (y1^y2)) == k){
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

        // For that we have to do precomputation as we move forward.

        // Now what we have to find is,
        // Current point, (x1, y1).

        // We have to find set of points used before such that,
        // (x1 ^ x) + (y1 ^ y) = k   ............ equation 0.
        // From this we can conclude that,
        // (x1 ^ x) = val .... equation 1.
        // (y1 ^ y) = (k - val) ..... equation 0.

        // Using (a^b) = c, then (c^a) = b.
        // From 1 and 2,
        // we have, (x1^val) = x,
        // we have, (y1^(k - val)) = y,
        // So our val goes from (0, k), therefore we just traverse through
        // all possible values of val to get Pairs of (x, y), satisfying equation 0.

        map<pair<int, int>, int> mp; // storing the visited points till now.

        int n = coordinates.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            for (int val = 0; val <= k; val++)
            {
                int x = (val ^ coordinates[i][0]);
                int y = ((k - val) ^ coordinates[i][1]);

                ans += mp[make_pair(x, y)];
            }

            mp[make_pair(coordinates[i][0], coordinates[i][1])]++;
        }
        return ans;
    }
};