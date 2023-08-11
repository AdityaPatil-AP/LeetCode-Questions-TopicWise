class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        stack<pair<int, int>> st;
        st.push({nums[0], 0});

        int steps = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int temp = 0;
            while (!st.empty() && st.top().first <= nums[i])
            {
                temp = max(temp, st.top().second);
                st.pop();
            }

            if (!st.empty())
            {
                temp += 1;
            }
            else
            {
                temp = 0;
            }

            steps = max(steps, temp);
            st.push({nums[i], temp});
        }

        return steps;
    }
};