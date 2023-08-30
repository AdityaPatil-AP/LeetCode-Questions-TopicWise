class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        // Find the minimum number of operations to make array sorted.
        long long answer = 0;

        int n = nums.size();
        int prev = nums[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] <= prev)
            {
                prev = nums[i];
                continue;
            }

            long long numElements = ceil((nums[i] + prev - 1ll) / prev);
            answer += numElements - 1;
            prev = nums[i] / numElements;
        }

        return answer;
    }
};

class Solution
{
public
    long minimumReplacement(int[] nums)
    {
        long answer = 0;
        int n = nums.length;

        // Start from the second last element
        int last = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= last)
            {
                last = nums[i];
            }
            else
            {
                int numElements = nums[i] / last;
                if (nums[i] % last != 0)
                    numElements++;

                answer += numElements - 1;

                last = (nums[i] / (numElements));
            }
        }

        return answer;
    }
}