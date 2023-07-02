class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        if (n <= 2)
            return n;
        // Brute Force appraoch.
        // Some precomputation which solves it in O(n) or O(n*log(n)) time.

        //         int ans = INT_MIN;
        //         for(int i = 0;i < n;i++){
        //             map<int,int> mp;
        //             int count = 0; // count of unique fruits that i have picked starting from ith index.
        //             int cur = 0;
        //             for(int j = i;j < n;j++){
        //                 if(mp[fruits[j]] == 0){
        //                     mp[fruits[j]]++;
        //                     count++;
        //                 }
        //                 if(count > 2) break;
        //                 cur++;
        //             }
        //             ans = max(ans, cur);
        //         }

        //         return ans;

        // Using dynamic sized windows.
        int j = 0;
        int i = 0;
        map<int, int> mp;
        int ans = INT_MIN;
        while (j < fruits.size())
        {
            mp[fruits[j]]++;
            if (mp.size() <= 2)
            {
                ans = max(ans, (j - i + 1));
            }
            else
            {
                while (mp.size() > 2)
                {
                    mp[fruits[i]]--;
                    if (mp[fruits[i]] == 0)
                    {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};