class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        // Editorial.
        if (s.size() != goal.size())
        {
            return false;
        }

        if (s == goal)
        {
            // If one character is appearing multiple times then we can retain
            // the same string and both s and goal still match each other.

            unordered_map<char, int> mp;

            for (auto it : s)
            {
                mp[it]++;
                if (mp[it] == 2)
                    return true;
            }

            return false;
        }

        // If they become equal after one swap which means before there were only two
        // indices which were mismatched already.
        int firstIndex = -1;
        int secondIndex = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                if (firstIndex == -1)
                {
                    firstIndex = i;
                }
                else if (secondIndex == -1)
                {
                    secondIndex = i;
                }
                else
                {
                    return false;
                }
            }
        }

        // If only one index is mismatched. Then also it is impossible for us to
        // make them equal after one swap.
        if (secondIndex == -1)
        {
            return false;
        }

        return (s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex]);

        // int change = 0;

        // if(s.size() != goal.size()){
        //     return false;
        // }

        // map<char, int> mp;
        // string difference1, difference2;

        // for(int i = 0;i < s.size();i++){
        //     if(s[i] != goal[i]){
        //         change++;
        //         difference1 += s[i];
        //         difference2 += goal[i];
        //     }
        //     else{
        //         mp[s[i]]++;
        //     }
        // }

        // // change is 0 and there are same matching characters.
        // bool isDouble = false;
        // for(auto it : mp){
        //     if(it.second >= 2) isDouble = true;
        // }

        // if(change == 2){
        //     sort(begin(difference1), end(difference1));
        //     sort(begin(difference2), end(difference2));
        //     if(difference1 == difference2)
        //         return true;
        //     else
        //         return false;
        // }

        // // If the strings are same and one character is appearing multiple times
        // // in that case we can swap those indices and still they are same.
        // if(change == 0 && isDouble) return true;

        // return false;
    }
};