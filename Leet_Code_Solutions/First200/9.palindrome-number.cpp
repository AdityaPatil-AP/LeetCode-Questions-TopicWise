class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        return (s == t);

        // can also do using a vector<int> and then using two pointer approach.
    }
};