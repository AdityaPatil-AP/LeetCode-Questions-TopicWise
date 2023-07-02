class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        // Goal - minimum operations to reduce the sum of nums by half.
        priority_queue<double> maxHeap(nums.begin(), nums.end());

        long minOperations = 0;

        long double sum = accumulate(nums.begin(), nums.end(), 0.0);
        long double currsum = sum;
        while (currsum > (sum / 2))
        {
            currsum -= maxHeap.top() / 2;
            double rem = maxHeap.top() / 2;
            maxHeap.pop();
            maxHeap.push(rem);
            minOperations++;
        }
        return minOperations;
    }
};