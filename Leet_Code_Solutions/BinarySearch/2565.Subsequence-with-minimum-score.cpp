class Solution
{
public:
    bool isSubsequence(string &t, string &s)
    {
        int s_ind = 0;
        for (int t_ind = 0; t_ind < t.size(); t_ind++)
        {
            while (s_ind < s.size())
            {
                if (s[s_ind] == t[t_ind])
                    break;
                s_ind++;
            }
            if (s_ind == s.size())
                return false;
            s_ind++;
        }
        // cout << "YES" << endl;
        return true;
    }

    vector<int> prefCalc(string s, string t)
    {
        vector<int> ans(t.size(), s.size());
        int s_ind = 0;
        for (int t_ind = 0; t_ind < t.size(); t_ind++)
        {
            while (s_ind < s.size())
            {
                if (s[s_ind] == t[t_ind])
                    break;
                s_ind++;
            }
            if (s_ind == s.size())
                return ans;
            ans[t_ind] = s_ind;
            s_ind++;
        }

        return ans;
    }

    vector<int> suffCalc(string s, string t)
    {
        vector<int> ans(t.size(), -1);
        int s_ind = s.size() - 1;
        for (int t_ind = t.size() - 1; t_ind >= 0; t_ind--)
        {
            while (s_ind >= 0)
            {
                if (s[s_ind] == t[t_ind])
                    break;
                s_ind--;
            }
            if (s_ind == -1)
                return ans;
            ans[t_ind] = s_ind;
            s_ind--;
        }

        return ans;
    }

    int minimumScore(string s, string t)
    {
        // Brute Force Approach.
        int n = s.size();
        int m = t.size();

        // it is already a subsequence the return 0.
        if (isSubsequence(t, s))
        {
            return 0;
        }

        // l, and r as starting and ending points of the part that has to be removed.
        int result = m;

        vector<int> prefInd = prefCalc(s, t);
        vector<int> suffInd = suffCalc(s, t);

        // Converted from O(n ^ 3) to O(n ^ 2).
        //         for(int l = 0;l < m;l++){
        //             for(int r = l;r < m;r++){
        //                 // string new_t = "";
        //                 // if(l >= 0) new_t += t.substr(0, l);
        //                 // if(r + 1 < n) new_t += t.substr(r + 1);
        //                 // if(isSubsequence(new_t, s)){
        //                 //     // cout << l << " " << r << endl;
        //                 //     result = min(result, r - l + 1);
        //                 // }

        //                 bool isPossible = false;
        //                 if(l == 0 && r == m - 1) isPossible = true;
        //                 else if(l == 0) isPossible = -1 < suffInd[r + 1];
        //                 else if(r == m - 1) isPossible = prefInd[l - 1] < n;
        //                 else if(l >= 1 && r + 1 < m) isPossible = prefInd[l - 1] < suffInd[r + 1];
        //                 if(isPossible){
        //                     // cout << l << " " << r << endl;
        //                     result = min(result, r - l + 1);
        //                 }
        //             }
        //         }

        // O(n^2) -> O(n*log(n)).
        for (int l = 0; l < m; l++)
        {
            if (l > 0 && prefInd[l - 1] == n)
                continue;
            int pref = -1;
            int valid_after = (l > 0) ? prefInd[l - 1] : -1;
            int r = upper_bound(suffInd.begin(), suffInd.end(), valid_after) - suffInd.begin();

            result = min(result, r - l);
        }

        return result;
    }
};