class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        // This is an array question, + subarrays + window size of 3. - every subarray's maximum value 
        // to be inserted in the ans.
        // So this is Fixed size Sliding Window question.
        int i = 0, j = 0; // They will denote the start and the end of my window.
        // List of integers - going to store the probable maximum elements for the subarray.
        // list<int> l;
        // Using deque.
        deque<int> dq;
        while(j < n){
            // Calculations for each element simultaneously..
            while(dq.size() > 0 && dq.back() < arr[j]){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            
            // If the window size is less than the required window.
            if((j - i + 1) < k){
                j++;
            }
            // If window size hits the required window size.
            else if((j - i + 1) == k){
                // ans <- calculations..
                // After doing calculations we expect that the largest element is at the start of the array.
                ans.push_back(dq.front());
                
                // Sliding the Window..
                // While sliding we have to remove the calculations for the current i.
                if(dq.size() > 0 && dq.front() == arr[i]){
                    dq.pop_front();
                }
                i++, j++; // maintaining the size of the window and sliding it.
            }
        }
        return ans;
    }
};