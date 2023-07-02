class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // Return the minimum number of operations(to convert white to black block) in one of the possible 
        // substrings of consecutive blocks of size k.(so that all of them are of black colour).
        // string -> substring -> window size k -> minimum operations
        int mincount = INT_MAX;
        int i = 0, j = 0; // creation of the window.
        // denoting the number of white blocks in the current window.
        int count = 0;
        while(j < blocks.size()){
            // calculations.
            // If we encounter any white block which means we will require one operation
            // to convert it from white to black block for the current window.
            if(blocks[j] == 'W') count++;
            // Creating the required window size.
            if((j - i + 1) < k){
                j++;
            }
            else if((j - i + 1) == k){
                // ans <- calculations.
                // We will only store the minimum number of operations required.
                mincount = min(mincount, count);
                
                // sliding the window.
                // 1) Removing the calculations for i.
                // If we are removing white block from our window which means one operation 
                // will not be required now.
                if(blocks[i] == 'W') count--;
                i++, j++; // Maintaining the size of the window.
            }
        }
        return mincount;
    }
};