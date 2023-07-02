class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0, j = 0;
        int n = pushed.size();
        stack<int> st;
        // if i == n, return false;
        // if i == n and j == n return true;
        // Use a while loop instead.
        while (i < n && j < n)
        {
            if (st.empty() || i < n)
            {
                st.push(pushed[i]);
                i++;
            }
            while (!st.empty() && popped[j] == st.top())
            {
                st.pop();
                j++;
            }
        }

        if (i == n && j == n)
        {
            return true;
        }
        return false;
    }
};