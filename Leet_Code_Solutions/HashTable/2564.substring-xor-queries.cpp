class Solution
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {
        // Leader Solution.
        //         int n = s.size();

        //         unordered_map<int, vector<int>> avail;

        //         for(int i = 0;i < n;i++){
        //             if(s[i] == '1'){
        //                 int val = 0;
        //                 for(int j = i;j < min(n, i + 31);j++){
        //                     val *= 2;
        //                     if(s[j] == '1') ++val;
        //                     if(!avail.count(val)) avail[val] = {i, j};
        //                 }
        //             }
        //             else if(!avail.count(0)) avail[0] = {i, i};
        //         }

        //         vector<vector<int>> ans;
        //         for(auto &q : queries){
        //             int v = q[0] ^ q[1];
        //             if(avail.count(v)) ans.push_back(avail[v]);
        //             else ans.push_back({-1, -1});
        //         }

        //         return ans;

        // mistakes i committed.
        // 1) most important mistake was bit manipulation should have been used.
        // - second = first ^ final;
        // 2) use of first0 variable rather than that i should  have simply checked for '0' and then updated
        // for 0 accordingly.
        // 3) our values should have started with only 1 for the shortest substring.
        // therefore that is one mistake i need to improve.
        // 4) exceeding the range of integer. therefore should have added the i + 30.

        // Things i did correct.
        // 1) using an unordered_map(O(n * 32)) for storing the unique numbers and their earliest occurence.
        // 2) then thinking about bit manipulation.
        // 3) successfully accepted.

        // Precomputation.
        // Will store the minimum index range where they were formed.
        int n = s.size();
        map<int, vector<int>> mp;
        bool first0 = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (!mp.count(0))
                {
                    mp[0] = {i, i};
                }
            }
            else
            {
                int val = 0;
                for (int j = i; j < min(n, i + 31); j++)
                {
                    val *= 2;
                    if (s[j] == '1')
                        ++val;
                    if (mp.find(val) == mp.end())
                    {
                        mp[val] = {i, j};
                    }
                }
            }
        }
        // precomputation done.
        // for(auto it : mp){
        //     cout << it.first << " " << it.second[0] << " " << it.second[1] << endl;
        // }

        vector<vector<int>> ans;

        for (auto query : queries)
        {
            int first = query[0];
            int final1 = query[1];
            int x = first ^ final1;
            // cout << x << endl;
            if (mp.find(x) != mp.end())
            {
                ans.push_back(mp[x]);
            }
            else
                ans.push_back({-1, -1});
        }

        return ans;
    }
};