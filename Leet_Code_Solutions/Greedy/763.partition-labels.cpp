class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // First though -> check for the first and the last occurence of the
        // characters and get a idea from it.

        vector<int> first(26, -1);

        vector<int> last(26, -1);

        int n = s.size();

        // for storing the first occurence.
        for (int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';
            if (first[curr] == -1)
                first[curr] = i;
        }

        // for storing the last occurence.
        for (int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';
            last[curr] = i;
        }

        int i = 0;
        vector<int> ans;
        while (i < n)
        {
            int size = 0;
            int start = i;
            int end = last[s[i] - 'a'];

            while (start != end)
            {
                size++;
                end = max(end, last[s[start] - 'a']);
                start++;
            }

            ans.push_back(size + 1);

            i = end + 1;
        }

        return ans;
    }
};