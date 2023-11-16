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
        // unordered_set<string> st;

        // for(string curr : nums) st.insert(curr);

        // int n = nums.size();
        // int last = pow(2, n);

        // for(int i = 0;i < last;i++){
        //     string curr = generate(i, n);

        //     if(st.find(curr) == st.end()){
        //         return curr;
        //     }
        // }

        // return "-1";

        unordered_set<int> st;
        for (string num : nums)
        {
            int curr = generate(num);
            st.insert(curr);
        }

        int n = nums.size();
        int last = pow(2, n);
        for (int i = 0; i < last; i++)
        {
            if (st.find(i) == st.end())
            {
                return generate(i, n);
            }
        }

        return "-1";
    }

    int generate(string curr)
    {
        int num = 0;
        int n = curr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            num += (curr[i] == '1') ? pow(2, n - i - 1) : 0;
        }

        return num;
    }
};