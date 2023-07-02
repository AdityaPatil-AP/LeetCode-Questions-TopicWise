class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // Find the difference of the largest with everyone else.

        long long mini = *min_element(nums.begin(), nums.end()) * n;

        long long sum = accumulate(nums.begin(), nums.end(), 0);

        return (sum - mini);
    }
};