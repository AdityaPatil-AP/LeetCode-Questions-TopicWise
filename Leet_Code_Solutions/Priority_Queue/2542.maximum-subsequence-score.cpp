class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // We have to choose  k indices,    in such a way that the score is maximum.

        // In score calculation there are two parts, first the addition part which is not that helpful.
        // And the second part is the minimum part which can be used optimally.

        // Here brute force would be to choose k indices out of n total indices, and then calculate
        // their score in O(k), the time complexity of this process is huge.

        // How to optimise this, for that we can optimise the minimum part,
        // The minimum at max can take n distinct values, for every minimum, we will choose the
        // most optimum (k - 1) indices to go with it.

        // So if we pair the nums1[i] values with their nums2[i] values and store them, sort them
        // in descending order of nums2[i], then the calculation of score, would be easier for the
        // chosen minimum, Because before computing the current minimum we have computed the
        // answer for the previous minimum, with the help of it, we are finding the answer for the
        // current one.

        // We have to use the answers of previous maximums.
        vector<vector<int>> pair;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            pair.push_back({nums2[i], nums1[i]});
        }
        sort(pair.begin(), pair.end(), greater<vector<int>>());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long sum = 0;
        for (auto i : pair)
        {
            pq.push(i[1]);
            sum += i[1];
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                ans = max(ans, sum * i[0]);
            }
        }

        return ans;
    }
};