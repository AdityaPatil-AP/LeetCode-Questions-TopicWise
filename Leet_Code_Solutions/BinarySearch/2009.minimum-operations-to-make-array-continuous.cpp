class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        // Sort the array.
        sort(nums.begin(), nums.end());

        // For array to be continuous, all element unique and difference between
        // maximum and minimum element is (n - 1).
        // Which means the element are in the order,
        // (min, min + 1, min + 2, .... , min + (n - 1));

        // Those which are present in this part will not be required to change if present in the array.
        // others have to changed to unselected values in this range.

        // This procedure needs to done for every value in nums[i].

        int n = nums.size();

        int minOp = n;
        // There may be duplicate values which should not be there.
        set<int> st;
        for (auto it : nums)
            st.insert(it);
        nums.clear();
        for (auto it : st)
            nums.push_back(it);

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            int last = nums[i] + n - 1;

            int j = upper_bound(nums.begin() + i, nums.end(), last) - (nums.begin());
            j--;

            int idx = j;

            int currOp = (n - (idx - i + 1));

            minOp = min(minOp, currOp);
        }

        return minOp;
    }
};