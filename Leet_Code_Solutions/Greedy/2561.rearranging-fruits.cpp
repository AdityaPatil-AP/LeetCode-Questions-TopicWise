class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        int n = basket1.size();
        map<int, int> mp1;
        map<int, int> mp2;

        for (int i = 0; i < basket1.size(); i++)
        {
            mp1[basket1[i]]++;
        }

        for (int i = 0; i < basket2.size(); i++)
        {
            mp2[basket2[i]]++;
        }

        // if the sum of frequencies of an element in both the arrays is odd,
        // return -1.

        for (auto it : mp1)
        {
            int elementCount = mp2[it.first] + it.second;
            if (elementCount % 2 == 1)
                return -1;
        }

        for (auto it : mp2)
        {
            int elementCount = mp1[it.first] + it.second;
            if (elementCount % 2 == 1)
                return -1;
        }

        // we will make two arrays more for storing the elements which need to swapped and sort them.
        vector<int> arr1;
        vector<int> arr2;

        for (int i = 0; i < n; i++)
        {
            if (mp1[basket1[i]] != 0 && mp2[basket1[i]] != 0)
            {
                mp1[basket1[i]]--;
                mp2[basket1[i]]--;
            }
            else
            {
                arr1.push_back(basket1[i]);
                mp1[basket1[i]]--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mp2[basket2[i]] != 0)
            {
                arr2.push_back(basket2[i]);
                mp2[basket2[i]]--;
            }
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int mini = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
        int m = arr1.size();
        long long ans = 0;
        for (int i = 0; i < m; i += 2)
        {
            ans += min(min(arr1[i], arr2[m - i - 1]), 2 * mini);
        }
        return ans;
    }
};