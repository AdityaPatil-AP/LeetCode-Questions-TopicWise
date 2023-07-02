class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        int ans = -1;
        // string + substring + k(maximum window size) + condition is - k Unique characters.
        // It's an variable size Sliding Window Question.
        int i = 0, j = 0;
        int size = s.size();
        unordered_map<char, int> mp;
        while(j < size){
            // As we are moving on we will do the calculations
            // Here if we encounter a letter we will increment it's frequency.
            mp[s[j]]++;
            
            if(mp.size() < k){
                j++;
            }
            else if(mp.size() == k){
                // ans <- calculations
                ans = max(ans, (j - i + 1));
                j++;
            }
            else if(mp.size() > k){
                while(mp.size() > k){
                    // Remove calculations for i.
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};