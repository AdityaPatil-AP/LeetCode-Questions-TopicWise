class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());

        // Creation of Duplicates free array.
        vector<int> arr(st.begin(), st.end());
        // Sorting it.
        sort(arr.begin(), arr.end());

        // Using Binary Search. Searching -> O(logn).
        // Keeping track of minimum operations.
        // Initially it would be
        // int minOperations = n;
        // int m = arr.size();
        // for(int i = 0;i < m;i++){
        //     // Creating a range to search for desired numbers.
        //     int left = arr[i];
        //     int right = left + (n - 1);

        //     int j = upper_bound(arr.begin(), arr.end(), right) - arr.begin();

        //     // Numbers in desired range.
        //     int desiredCount = j - i;

        //     // Numbers to be replaced;
        //     int replaceCount = n - desiredCount;

        //     minOperations = min(minOperations, replaceCount);
        // }

        // Searching for an individual range is O(1) considered overall.
        // Using Sliding Window.
        int minOperations = n;
        int m = arr.size();
        int j = 0; // Points to next bigger element ahead of right for range of
        // [left, right].
        for (int i = 0; i < m; i++)
        {
            int left = arr[i];
            int right = left + (n - 1);

            while (j < m && arr[j] <= right)
            {
                j++;
            }

            int desiredCount = j - i;

            minOperations = min(minOperations, n - desiredCount);
        }

        return minOperations;
    }
};