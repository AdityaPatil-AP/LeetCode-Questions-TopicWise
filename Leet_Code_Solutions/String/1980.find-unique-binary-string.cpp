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

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<int> integers;
        for (string num : nums)
        {
            integers.insert(stoi(num, nullptr, 2));
        }

        int n = nums.size();

        for (int num = 0; num <= n; num++)
        {
            if (integers.find(num) == integers.end())
            {
                string ans = bitset<16>(num).to_string();
                return ans.substr(16 - n);
            }
        }

        // Unreachable position.
        return "";
    }
};

class Solution
{
public:
    unordered_set<int> integers;

    string generate(string curr)
    {
        if (curr.size() == integers.size())
        {
            int val = stoi(curr, 0, 2);
            if (integers.find(val) == integers.end())
            {
                return curr;
            }

            return "";
        }

        string addZero = generate(curr + "0");
        if (addZero.size() > 0)
        {
            return addZero;
        }

        return generate(curr + "1");
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        for (auto num : nums)
        {
            integers.insert(stoi(num, 0, 2));
        }

        return generate("");
    }
};