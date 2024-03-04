class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        string ans;
        sort(s.begin(), s.end(), greater<char>());
        cout << s << endl;
        ans = s.substr(1);
        ans += s[0];
        return ans;
    }
};
