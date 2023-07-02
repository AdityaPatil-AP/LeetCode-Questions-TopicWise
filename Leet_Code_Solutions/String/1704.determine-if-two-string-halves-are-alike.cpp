class Solution
{
public:
    bool halvesAreAlike(string S)
    {
        // int mid = S.size() / 2, ans = 0;
        // for (int i = 0, j = mid; i < mid; i++, j++) {
        //     if (~vowels.find(S[i])) ans++;
        //     if (~vowels.find(S[j])) ans--;
        // }
        // return ans == 0;

        // int mid = S.size()/2;
        // int ans = 0;
        // for(int i = 0, j = mid;i < mid;i++, j++){
        //     if(~vowels.find(S[j])) ans--;
        //     if(~vowels.find(S[i])) ans++;
        //     cout << ans << endl;
        // }
        // // cout << ans << endl;
        // return ans == 0;

        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = S.size() / 2;
        int cnt = 0;
        while (j < S.size())
        {
            if (st.find(S[j]) != st.end())
                cnt++;
            if (st.find(S[i]) != st.end())
                cnt--;
            i++, j++;
        }
        return cnt == 0;
    }
};