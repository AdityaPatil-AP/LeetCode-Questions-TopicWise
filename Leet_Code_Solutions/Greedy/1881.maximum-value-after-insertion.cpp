class Solution
{
public:
    string maxValue(string n, int x)
    {
        // s ->  count of digits in n. Then by adding x we can create (s + 1) different
        // numbers.

        // For positive numbers -> it should be placed before the first smallest digit
        // that is less than x.

        // For negative numbers -> It should be placed before the first digit that is
        // greater than it.

        int sign = 1, start = 0;
        int original_length = n.size();
        if (n[0] == '-')
        {
            sign = -1;
            start = 1;
        }

        for (int i = start; i < n.size(); i++)
        {
            int num = n[i] - '0';

            // insert x where smaller number occurs.
            if (num * sign < sign * x)
            {
                n.insert(i, to_string(x));
                break;
            }
        }

        if (n.size() == original_length)
        {
            n.insert(n.size(), to_string(x));
        }

        return n;
    }
};