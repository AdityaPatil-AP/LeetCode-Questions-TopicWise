class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // We are given to find all anagrams occurences of string p in string s.
        // Anagrams are words formed by rearranging the letters of the word, typically using all the letters exactly once.
        // 1) First inference from anagrams :
        // Which gives us an idea, they all have same size.
        // 2) Second inference - They all have same letters with the same frequency corresponding to each letter.

        // Brute force way to solve this problem is would be to generate all the anagrams and then search for the
        // occurences of them in the string using some some string matching algorithm like KMP.
        // But generating all the anagrams would take O(n!) time complexity + the matching complexity depending upon
        // the matching algorithm.

        // So it's obvious that we will not use that algorithm.
        // Now we can see that we have to search anagrams of fixed size k.
        // These anagrams are also continuous. They can be treated as a substring of size k.
        // So let's start searching for them from the start of the array.
        // Now we will check the letters stored in the first k characters of the string.
        // So we have to store the letters and their corresponding frequencies of the of the letters present in the pattern.
        // Till now we have guessed it is a typical sliding window problem. Because we have to check for every index from
        // 0 until n - k(pattern length), that whether this window is an anagram or not.
        // At first we will create the map for the pattern.
        // Here we have to even keep a count variable because count will denote the number of non-zero frequency
        // elements present in the map. It will help us to save time to check if all letters have zero frequency
        // wala stuff. If count == 0, means all letters have zero frequency or else some elements may have non-zero
        // frequency.
        int count = 0;
        map<char, int> mp;
        for (auto it : p)
        {
            mp[it]++;
        }
        // Initially it will have non-zero element equal to mp.size().
        count = mp.size();
        // Then find the window size which is the size of the pattern in this case.
        int k = p.size();
        // i, j denoting the start and the end of the window.
        int i = 0, j = 0;
        // storing the indices where the anagram starts.
        vector<int> ans;
        while (j < s.size())
        {
            // Calculations, For every j, if it is present in the map(denoting it is part of the pattern)
            // we decrement frequency corresponding to that letter..
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                // if the frequency of the letter becomes zero, then count of non-zero frequency letters is also
                // decremented.
                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }
            // If the window size is less than the required window size, then go for the next element.
            if ((j - i + 1) < k)
            {
                j++;
            }
            // If the window size hits the required window size then we have to use the calculations done for
            // that window for finding the answer.
            else if ((j - i + 1) == k)
            {
                // ans <- calculations.
                if (count == 0)
                {
                    ans.push_back(i);
                }
                // Sliding the window ahead.
                // Now while sliding we are deleting the start of this window, so we have to remove the calculations
                // related to it. Those were if it was present in the map we decremented it's frequency, now if
                // we are removing it we have increase it's corresponding frequency.
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    // And also we have to check now if it's frequency becomes 1, when earlier it was 0, because now
                    // it will contribute the count,
                    if (mp[s[i]] == 1)
                        count++;
                }
                // Maintaining the size  of the window
                i++, j++;
            }
        }
        return ans;
    }
};