class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // O(n^2) solution.
        // vector<int> ans;

        // int n = temperatures.size();
        // for(int i = 0;i < n;i++){
        //     int curr_ans = i;
        //     for(int j = i + 1;j < n;j++){
        //         if(temperatures[j] > temperatures[i]){
        //             curr_ans = j;
        //             break;
        //         }
        //     }

        //     ans.push_back(curr_ans - i);
        // }

        // return ans;

        // O(n) solution using monotonic stack.
        deque<int> deque;

        int n = temperatures.size();

        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (deque.empty())
            {
                deque.push_front(i);
                ans[i] = 0;
            }
            else
            {
                while (!deque.empty() && temperatures[i] >= temperatures[deque.front()])
                {
                    deque.pop_front();
                }

                if (deque.empty())
                {
                    ans[i] = 0;
                }
                else
                {
                    ans[i] = deque.front() - i;
                }

                deque.push_front(i);
            }
        }

        return ans;
    }
};