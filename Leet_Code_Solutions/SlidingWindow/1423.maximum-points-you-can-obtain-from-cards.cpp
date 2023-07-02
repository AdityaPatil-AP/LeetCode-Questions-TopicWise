class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // // This is a Prefix Sum + Sliding Window Problem..
        // int n = cardPoints.size();
        // vector<int> pStart(n, 0);
        // vector<int> pEnd(n, 0);
        // int startSum = 0, endSum = 0;
        // // Prefix Sum from Start and End Calculated.
        // for(int i = 0, j = n - 1;i < n;i++, j--){
        //     startSum += cardPoints[i];
        //     endSum += cardPoints[j];
        //     pStart[i] = startSum;
        //     pEnd[j] = endSum; 
        // }
        // // 1) Either all elements are selected from the start.
        // // 2) Or All the elements are selected from the end.
        // // 3) Some are selected from the start and some are selected from the end.
        // // As we have calculated the prefix sum from the start and the end.  
        // // 1-Case will be at pStart[k - 1], 2-Case will be at pEnd[(n - 1) - (k - 1)].
        // int ans = max(pStart[k - 1], pEnd[(n - 1) - (k - 1)]);
        // // Now let's handle the third Case. 
        // // This means we have atleast 1 card selected from the start and some cards from last and vice-versa.
        // // Creating a Window of Size k
        // for(int i = k - 2, j = n - 1;i >= 0;i--, j--){
        //     ans = max(pStart[i] + pEnd[j], ans);
        // }
        // return ans;
        
        // Another Way Using Sliding Window + Prefix Sum.
        int res = 0;
        // First Creating a window with k elements from the Start.
        for(int i = 0;i < k;i++) res += cardPoints[i];
        
        // Now It may happen we may choose some elements from first and other from the last.
        int curr = res;
        for(int i = k - 1;i >= 0;i--){
            // Creating Possible Combinations. Like starting se (k - 1) cards and end se 1 card. or starting
            // se (k - 2) cards and end se 2 cards. and so on. 
            // Therefore whichever combination gives us the maximum points is our answer.
            // Removing the recently visited element from the first.
            curr -= cardPoints[i];
            // and adding the non-visited element from the last.
            curr += cardPoints[cardPoints.size() - k + i];
            
            // Finding the maximum score of all the Combinations.
            res = max(res, curr);
        }
        return res;
    }
};