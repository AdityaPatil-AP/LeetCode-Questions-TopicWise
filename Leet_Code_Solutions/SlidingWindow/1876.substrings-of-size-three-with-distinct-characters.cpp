class Solution {
public:
    int countGoodSubstrings(string s) {
        // string + substring + window size k + return count question
        // Fixed sliding window question.
        // now in the substring we want all the unique characters.
        // We should store the frequencies of all the letters for checking that 
        // if in substring we have unique characters or not for that 
        // our data structure which is map in this case should should have size equal to the window 
        // size. 
        // Setting our window by using i and j.
        int i = 0, j = 0;
        unordered_map<char, int> ump;
        // Will store the number of substring with unique characters.
        int count = 0;
        while(j < s.size()){
            // Calculationms
            ump[s[j]]++;
            
            // If window size is less than the required size.
            if((j - i + 1) < 3){
                j++;
            }
            else if((j - i + 1) == 3){
                // ans <- calculations
                if(ump.size() == 3){
                    count++;
                }
                // Sliding the Window.
                ump[s[i]]--;
                // if the frequency of the letter becomes zero then delete the letter from the map.
                if(ump[s[i]] == 0){
                    ump.erase(s[i]);
                }
                i++, j++; // maintain the size of the window.
            }
        }
        return count;
    }
};