class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           // String + substring + Condition => longest size.
        // Variable Sliding Window Question
        int i = 0, j = 0;
        // They are asking for the unique characters.
        int size = s.size();
        // characters must be stored in some set or map, let's use map it can be done using set as well.
        unordered_map<char, int> ump;
        int mx = 0;
        while(j < size){
            // Calculations
            ump[s[j]]++;
            if(ump.size() == (j - i + 1)){
                // ans<-calculations
                mx = max(mx, (j - i + 1));
                j++;
            }
            else if(ump.size() < (j - i + 1)){
                if(ump.size() < (j - i + 1)){
                    ump[s[i]]--;
                    if(ump[s[i]] == 0){
                        ump.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};

// Alternative Solution without using a hashmap

int longestUniqueSubsttr(string s){
        //code
        // Variable Sliding Window Question
        int i = 0, j = 0;
        // They are asking for the unique characters.
        int size = s.size();
        // characters must be stored in some set or map, let's use map it can be done using set as well.
        int arr[26] = {0};
        int count = 0;
        int mx = 0;
        while(j < size){
            // Calculations
            arr[s[j] - 'a']++;
            if(arr[s[j] - 'a'] == 1){
                count++;
            }
            if(count == (j - i + 1)){
                // ans<-calculations
                mx = max(mx, (j - i + 1));
                j++;
            }
            else if(count < (j - i + 1)){
                if(count < (j - i + 1)){
                    arr[s[i] - 'a']--;
                    if(arr[s[i] - 'a'] == 0){
                        count--;
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }