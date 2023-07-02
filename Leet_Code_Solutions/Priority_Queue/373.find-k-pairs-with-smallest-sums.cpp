class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // Effecient One.
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

        vector<vector<int>> ans;

        set<pair<int, int>> visited;

        visited.insert({0, 0});
        pq.push({nums1[0] + nums2[0], {0, 0}});

        while (k-- && !pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // Two pairs that can be insert for the current pair.
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end())
            {
                pq.push({(long long)nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                pq.push({(long long)nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;

        // A bit higher time complexity.
        //         vector<vector<int>> ans;
        //         int pairsFound = 0;

        //         priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

        //         // Pick all the elements of nums1 with first element of nums2.
        //         for(int i = 0;i < nums1.size();i++){
        //             pq.push({(long long)nums1[i] + nums2[0], {i, 0}});
        //         }

        //         while(pairsFound < k && !pq.empty()){
        //             auto curr = pq.top();
        //             pq.pop();

        //             int i = curr.second.first;
        //             int j = curr.second.second;

        //             ans.push_back({nums1[i], nums2[j]});

        //             if(j != (nums2.size() - 1)){
        //                 pq.push({(long long)nums1[i] + nums2[j + 1], {i, j + 1}});
        //             }

        //             pairsFound++;
        //         }

        //         return ans;
    }
};