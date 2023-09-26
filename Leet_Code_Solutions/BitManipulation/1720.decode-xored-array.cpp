class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int size = encoded.size() + 1;
        vector<int> ans(size, 0);
        int curr = first;
        for (int i = 0; i < size - 1; i++)
        {
            ans[i] = curr;
            // We have to find the next.
            int next = curr ^ encoded[i];

            curr = next;
        }

        ans[size - 1] = curr;

        return ans;
    }
};