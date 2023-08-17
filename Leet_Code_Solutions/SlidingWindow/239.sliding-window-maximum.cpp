class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Rather than elements we are storing the indices to check whether are not
        // too left to the current index and present in our window.
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++)
        {
            if (dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

// In Java.

class Solution
{
public
    int[] maxSlidingWindow(int[] nums, int k)
    {
        Deque<Integer> dq = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < k; i++)
        {
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()])
            {
                dq.pollLast();
            }

            dq.offerLast(i);
        }

        res.add(nums[dq.peekFirst()]);

        for (int i = k; i < nums.length; i++)
        {
            if (dq.peekFirst() == i - k)
            {
                dq.pollFirst();
            }

            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()])
            {
                dq.pollLast();
            }

            dq.offerLast(i);
            res.add(nums[dq.peekFirst()]);
        }

        // returning the result as an array.
        return res.stream().mapToInt(i->i).toArray();
    }
}