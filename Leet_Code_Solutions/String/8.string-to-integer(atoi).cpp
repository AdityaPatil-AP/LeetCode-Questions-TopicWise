class Solution
{
public:
    int myAtoi(string s)
    {
        int len = s.size();

        int index = 0;
        bool isNegative = false;
        // Ignored leading whitespaces and took the number sign.
        while (s[index] == ' ' && index < len)
        {
            index++;
        }
        if (s[index] == '-')
        {
            isNegative = true;
            index++;
        }
        else if (s[index] == '+')
            index++;
        int result = 0;
        int min_limit = INT_MIN / 10;
        int max_limit = INT_MAX / 10;
        while (index < len && isDigit(s[index]))
        {
            int num = (s[index] - '0');
            if (!isNegative && (result > (max_limit) || (result == (max_limit) && num > 7)))
            {
                return INT_MAX;
            }
            else if (isNegative && (result > (max_limit) || (result == (max_limit) && num >= 8)))
            {
                return INT_MIN;
            }
            result = (result * 10) + num;
            index++;
        }

        return (isNegative) ? (-1 * result) : result;
    }

private:
    bool isDigit(char a)
    {
        return (a >= '0' && a <= '9');
    }
};