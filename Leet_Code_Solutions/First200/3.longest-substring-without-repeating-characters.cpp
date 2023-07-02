class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // String + substring + Condition => longest size.
        // Variable Sliding Window Question
        // int i = 0, j = 0;
        // // They are asking for the unique characters.
        // int size = s.size();
        // // characters must be stored in some set or map, let's use map it can be done using set as well.
        // unordered_map<char, int> ump;
        // int mx = 0;
        // while(j < size){
        //     // Calculations
        //     ump[s[j]]++;
        //     if(ump.size() == (j - i + 1)){
        //         // ans<-calculations
        //         mx = max(mx, (j - i + 1));
        //         j++;
        //     }
        //     else if(ump.size() < (j - i + 1)){
        //         if(ump.size() < (j - i + 1)){
        //             ump[s[i]]--;
        //             if(ump[s[i]] == 0){
        //                 ump.erase(s[i]);
        //             }
        //             i++;
        //         }
        //         j++;
        //     }
        // }
        // return mx;

        // Practice - 2nd time.

        // Variable Sliding Window Question.
        // longest Substring with no repeating characters. How would we find that.
        // we need a data structure for that, this data structure can be a map which stores the frequency.

        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int size = s.size();
        int mx = 0;
        while (j < size)
        {
            // Calculations
            mp[s[j]]++;

            if (mp.size() == (j - i + 1))
            {
                mx = max((j - i + 1), mx);
                j++;
            }
            else if (mp.size() < (j - i + 1))
            {
                while (mp.size() < (j - i + 1))
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};