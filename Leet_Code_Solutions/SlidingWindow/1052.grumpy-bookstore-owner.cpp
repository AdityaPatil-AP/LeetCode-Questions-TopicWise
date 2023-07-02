class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 1) array
        // 2) Subarray - Because the minutes for which we can keep our bookstore owner not
        // grumpy is consecutive.
        // 3) We are given a k sized interval.
        // Therefore it is a fixed Sized Sliding window question.
        // We have to return the maximum number of customers that were satisfied throughout
        // the day..
        // First step - Count the number of customers which are already satisfied when the 
        // bookstore owner was not grumpy.
        int ans = 0;
        int n = customers.size();
        for(int i = 0;i < n;i++){
            if(grumpy[i] == 0) ans += customers[i];
        }
        // We are given a secret technique by which we can keep out bookstore owner not grumpy.
        int i = 0, j = 0; // Creation of the window.
        int secretadd = 0; // In the minutes window, the extra customers which got satisfied.
        int maxadd = 0;
        while(j < n){
            // Calculations
            if(grumpy[j] == 1) secretadd += customers[j];
            
            if((j - i + 1) < minutes){
                j++;
            }
            else if((j - i + 1) == minutes){
                // ans <- calculations.
                maxadd = max(secretadd, maxadd);
                
                // Sliding the window. Before that
                // 1) Removing the Calculations for i.
                if(grumpy[i] == 1) secretadd -= customers[i];
                // 2) maintain the size of the window.
                i++, j++;
            }
        }
        return (ans + maxadd);
    }
};