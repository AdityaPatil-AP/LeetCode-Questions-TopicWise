class Solution {
public:
    int largestVariance(string s) {
        // Brute.
        // Check for all Substrings and after that, find the largest 
        // variance possible for that string.

        // Create a Map of frequency and iterate through it.
        // if only one character is present in the substring then lpv = 0.
        // else take the difference between minimum and maximum.

        // Create an answer variable to hold the lpv.

        // O(n^3).

        // How to optimise this.
        int global_max = 0;
        vector<int> counter(26, 0);
        for(auto ch : s){
            counter[ch - 'a']++;
        }

        for(int i = 0;i < 26;i++){
            for(int j = 0;j < 26;j++){
                if(i == j || counter[i] == 0 || counter[j] == 0){
                    continue;
                }

                char major = 'a' + i;
                char minor = 'a' + j;
                int majorcount = 0;
                int minorcount = 0;

                // Keeping a track of count of minor in the remaining string.
                int restminor = counter[j];

                int local_max = 0;
                int n = s.size();
                for(int k = 0;k < n;k++){
                    if(s[k] == major) majorcount++;
                    if(s[k] == minor){
                        restminor--;
                        minorcount++;
                    }

                    int local_max = majorcount - minorcount;

                    // We update our global_max only if atleast one major and 
                    // one minor is present in the substring.
                    if(minorcount > 0){
                        global_max = max(local_max, global_max);
                    }

                    // If local_max < 0, but we have some minors in the remaining
                    // string then we can reset local_max which is minor_count and major_count
                    // as 0. 
                    // But if not then we have to leave them as it is because we would
                    // require the previous minor encountered for our future local_max.
                    if(local_max < 0 && restminor > 0){
                        majorcount = 0;
                        minorcount = 0;
                    }
                }
            }
        }

        return global_max;
    }
};