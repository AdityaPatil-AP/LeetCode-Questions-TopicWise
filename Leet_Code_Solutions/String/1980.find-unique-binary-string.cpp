class Solution
{
public:
    string generate(int num, int n)
    {
        string curr;

        while (num > 0)
        {
            int rem = num % 2;
            curr += to_string(rem);
            num = num / 2;
        }

        while (curr.size() < n)
        {
            curr += '0';
        }

        reverse(curr.begin(), curr.end());

        return curr;
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<string> st;

        for (string curr : nums)
            st.insert(curr);

        int n = nums.size();
        int last = pow(2, n);

        for (int i = 0; i < last; i++)
        {
            string curr = generate(i, n);

            if (st.find(curr) == st.end())
            {
                return curr;
            }
        }

        return "-1";
    }
};