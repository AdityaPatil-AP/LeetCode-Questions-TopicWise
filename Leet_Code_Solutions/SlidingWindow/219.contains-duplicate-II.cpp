class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        // We cannot get two different indices in that case.
        if(k == 0){
            return false;
        }
        // Here we have an array + we are finding the answer in an window of size k + 1.
        // This is an fixed sliding window question.
        int winsize = k + 1;
        int i = 0, j = 0; // denote the start and the end of the sliding window.
        unordered_map<int, int> ump;
        int count = 0; // Explained below why we have declared it.
        while(j < arr.size()){
            // Calculations for j. In this case we have to keep the frequency of that element.
            ump[arr[j]]++;
            // We require a count variable which will tell us at any moment the number of elements which have 
            // frequency greater than 1. 
            // Why are we introducing it.
            // So whenever we hit the window size we don't have to traverse the whole map to check 
            // if any element have frequency greater than 1. Reducing a lot of time.
            if(ump[arr[j]] >= 2){
                return true;
            }
            // Increasing the window size.
            if((j - i + 1) < winsize){
                j++;
                if(count > 0){ 
                    return true;
                }
            }
            else if((j - i + 1) == winsize){
                // ans <- calculations
                if(count > 0){ 
                    return true;
                }
                // Maintain the window size.
                // Now before that we have to remove the calculations for i.
                ump[arr[i]]--;
                // then if the mp[arr[i]] == 1, this element was repeating more than once before but now 
                // it is unique in that window so, we do count--.
                if(ump[arr[i]] == 1){
                    count--;
                }
                // if element not present in the window at all, then remove it.
                if(ump[arr[i]] == 0){
                    ump.erase(arr[i]);
                }
                // maintain the window size.
                i++, j++;
            }
        }
        // If after traversing all the window sizes, we don't get any window which has repeating characters, 
        // then return false.
        return false;
    }
};