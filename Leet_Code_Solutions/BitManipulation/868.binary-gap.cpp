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
        int gap = 0;

        int last1 = -1;
        string num = binaryNumber(n);
        for (int i = 0; i < num.size(); i++)
        {
            if (last1 == -1 && num[i] == '1')
            {
                last1 = i;
            }
            else if (num[i] == '1')
            {
                gap = max(gap, i - last1);
                last1 = i;
            }
        }

        return gap;
    }
};