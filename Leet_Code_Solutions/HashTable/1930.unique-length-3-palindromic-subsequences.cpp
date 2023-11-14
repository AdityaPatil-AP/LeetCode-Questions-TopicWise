class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        // First Inference : Length 3 palindrome which means the first and last
        // character are going to be the same.

        // We have to find length 3 palindrome. Our middle element is going to be
        // different. It can be same as the first/last character.

        // How to maximise the number of subsequences.
        // If we choose the first occurence of current letter in s as i and the
        // last occurrence as j. Then for that letter we can found the maximum
        // number subsequences by counting the unique letters between them.

        // That is in the range of [i + 1, j - 1].

        // unordered_set<char> letters;

        // for(char c : s) letters.insert(c);

        // int ans = 0;
        // for(char letter : letters){
        //     int i = -1;
        //     int j = 0;

        //     for(int k = 0;k < s.size();k++){
        //         if(s[k] == letter){
        //             if(i == -1) i = k;
        //             j = k;
        //         }
        //     }

        //     unordered_set<char> between;
        //     for(int k = i + 1;k < j;k++){
        //         between.insert(s[k]);
        //     }

        //     ans += between.size();
        // }

        // return ans;

        // Approach 2 : PreCompute First and last indices.
        vector<int> last = vector(26, -1);
        vector<int> first = vector(26, -1);
        int n = s.size();
        unordered_set<char> letters;

        for (int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';

            if (first[curr] == -1)
                first[curr] = i;

            last[curr] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (first[i] != -1)
            {
                unordered_set<char> between;

                for (int k = first[i] + 1; k < last[i]; k++)
                {
                    between.insert(s[k]);
                }

                ans += between.size();
            }
        }

        return ans;
    }
};