class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string l = to_string(low);
        string h = to_string(high);

        vector<int> ans;
        for (int i = l.size(); i <= h.size(); i++)
        {
            deque<char> dq;

            for (int j = 1; j < i; j++)
            {
                char curr = '0' + j;
                dq.push_back(curr);
            }

            for (int j = i; j <= 9; j++)
            {
                char curr = '0' + j;
                dq.push_back(curr);

                string num;
                for (auto it = dq.begin(); it != dq.end(); it++)
                {
                    num.push_back(*it);
                }

                int cur = stoi(num);

                if (cur >= low && cur <= high)
                {
                    ans.push_back(cur);
                }

                dq.pop_front();
            }
        }

        return ans;
    }
};