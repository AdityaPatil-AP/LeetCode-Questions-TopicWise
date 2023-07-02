class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        // Didn't get the logic.
        // So referred the solution.

        // There came to know that the answer can be found using priority_queue and unordered_map
        // Why unordered_map? To store the frequency of every element.
        // Why priority_queue? This is because if we place highest frequency element first before others.
        // Then obviously our chances of getting a valid array increases.
        // Here we are assured a valid array exists. So this idea will work.

        int n = barcodes.size();

        if (n <= 2)
            return barcodes;

        unordered_map<int, int> mp;

        for (auto i : barcodes)
            mp[i]++;

        priority_queue<pair<int, int>> pq;

        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (pq.size() > 0)
        {
            auto top1 = pq.top();
            ans.push_back(top1.second);
            pq.pop();

            // Similarly we will also place the second most frequent element.
            if (pq.size() == 0)
                break;

            auto top2 = pq.top();
            ans.push_back(top2.second);
            pq.pop();
            // Now two element with the most frequent element has been worked upon.
            top1.first--;
            top2.first--;
            if (top1.first)
                pq.push(top1);
            if (top2.first)
                pq.push(top2);
        }

        return ans;
    }
};