class Solution {
public:
    bool valid(const string &s, int start, int length){
        return ((length == 1) || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255")));
    }
    
    void helper(int start, const string &s, vector<int> &dots, vector<string> &ans){
        int remainingLength = s.length() - start;
        int remainingNumberOfIntegers = 4 - dots.size();
        if(remainingNumberOfIntegers > remainingLength || 3 * remainingNumberOfIntegers < remainingLength){
            return;
        }
        // I have appended 3 dots till now I just have to check whether i can
        // add it as valid ip with the inclusion of the 4th valid integer.
        if(dots.size() == 3){
            // Now we have to create the last integers.
            if(valid(s, start, remainingLength)){
                string temp;
                int last = 0;
                for(int dot : dots){
                    temp.append(s.substr(last, dot));
                    last += dot;
                    temp.append(".");
                }
                temp.append(s.substr(start));
                ans.push_back(temp);
            }
            return;
        }
        
        for(int curPos = 1; curPos <= 3 && curPos <= remainingLength; ++curPos){
            // Append a dot at the current position.
            dots.push_back(curPos);
            // Try making all the combinations with the remaining string.
            if(valid(s, start, curPos)){
                helper(start + curPos, s, dots, ans);
            }
            // BackTrack, i.e. remove the dot to try placing it at the next position.
            dots.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        // Creation of helper function with the given parameters.
        vector<int> dots;
        vector<string> ans;
        // parameters - processing index, original string s, list of integers which
        // saves the distances or slots where dots are placed so far and a list of 
        // strings ans to save the answers.
        helper(0, s, dots, ans);
        return ans;
    }
};