class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
        {
            return {};
        }

        int start = nums[0];
        int end = nums[0];

        vector<string> ans;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {
                end++;
            }
            else
            {
                if (start != end)
                {
                    string curr = to_string(start) + "->" + to_string(end);
                    ans.push_back(curr);
                }
                else
                {
                    ans.push_back(to_string(start));
                }

                start = nums[i];
                end = nums[i];
            }
        }
        if (start != end)
        {
            string curr = to_string(start) + "->" + to_string(end);
            ans.push_back(curr);
        }
        else
        {
            ans.push_back(to_string(start));
        }

        return ans;
    }
};