class Solution {
public:
    int divisorSubstrings(int num, int k) {
        // Fixed Sliding Window question.
        // size k is mentioned with substring and string.
        // Find the count of the substrings of size k which also divide the num.
        int count = 0;
        int i = 0, j = 0;// creation of the window with i and j as starting and ending point respectively.
        string s = to_string(num);
        string sub;
        while(j < s.size()){
            // Calculations
            sub.push_back(s[j]);
            
            if((j - i + 1) < k) j++;
            else if((j - i + 1) == k){
                // ans <- calculations.
                // converting string to integer using stringstream.
                // int curnum;
                // stringstream g(sub);
                // g >> curnum;
                // Using stoi
                // int curnum = stoi(sub);
                // using atoi - we cannot use atoi here because it works for characters arrays and
                // string literals only. It is not applicable for c++ strings. It is C-style legacy function.
                if(curnum != 0) if(num % curnum == 0) count++;
                // sliding the window
                // Remove calculations for i.
                sub.erase(sub.begin());
                i++, j++;
            }
        }
        return count;
    }
};