class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX;
        
         // We will start by taking the intial values and multiply them by 2 for odd numbers.
        int mini = INT_MAX;
        priority_queue<int> pq;
        
        for(int n : nums){
            if(n % 2){
                n = n * 2;
            }
            
            mini = min(mini, n);
            pq.push(n);
        }
        
        while(pq.top() % 2 == 0){
            ans = min(ans, pq.top() - mini);
            mini = min(mini, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        
        return min(ans, pq.top() - mini);
    }
};