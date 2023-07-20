class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> pos, neg;
        int n = asteroids.size();
        vector<int> answer;

        for (int i = 0; i < n; i++)
        {
            int curr = asteroids[i];
            if (curr < 0)
            {
                bool isEqual = false;
                while (!pos.empty())
                {
                    if (pos.top() == abs(curr))
                    {
                        pos.pop();
                        isEqual = true;
                        break;
                    }
                    else if (pos.top() > abs(curr))
                    {
                        break;
                    }
                    else
                    {
                        pos.pop();
                    }
                }

                if (pos.empty() && !isEqual)
                {
                    neg.push(curr);
                }
            }

            else
            {
                pos.push(curr);
            }
        }

        vector<int> ans;
        while (!neg.empty())
        {
            ans.push_back(neg.top());
            neg.pop();
        }
        reverse(begin(ans), end(ans));
        vector<int> ans1;
        while (!pos.empty())
        {
            ans1.push_back(pos.top());
            pos.pop();
        }
        reverse(begin(ans1), end(ans1));
        for (auto i : ans1)
        {
            ans.push_back(i);
        }
        return ans;
    }
};