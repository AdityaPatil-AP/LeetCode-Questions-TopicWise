class Solution
{
public:
    string binaryNumber(int n)
    {
        int temp = n;
        string num;
        while (temp)
        {
            int rem = temp % 2;
            num += to_string(rem);
            temp /= 2;
        }

        reverse(num.begin(), num.end());

        return num;
    }

    int binaryGap(int n)
    {
        // String Representation.
        // int gap = 0;

        // int last1 = -1;
        // string num = binaryNumber(n);
        // for(int i = 0;i < num.size();i++){
        //     if(last1 == -1 && num[i] == '1'){
        //         last1 = i;
        //     }
        //     else if(num[i] == '1'){
        //         gap = max(gap, i - last1);
        //         last1 = i;
        //     }
        // }

        // return gap;

        // Using Bit Manipulation.
        // Right Shift Operators and Bitwise operators use karke.
        int last = -1, ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (((n >> i) & 1))
            {
                if (last >= 0)
                {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }

        return ans;
    }
};