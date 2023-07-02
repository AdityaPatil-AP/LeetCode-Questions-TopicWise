vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int k) {
    // Storing the first negative integer for all the subarrays.
    vector<long long> ans;
    // Storing the negative integers present in each subarray.
    list<int> negative;
    // i and j denoting the start and the end of the subarray.
    int i = 0, j = 0;
    while(j < N){
        // Calculations - adding every negative element of the subarray.
        if(arr[j] < 0) negative.push_back(arr[j]);
        // Checking if the window size.
        // if it is less than the required window size then we increase the our window size.
        if((j - i + 1) < k){
            j++;
        }
        // If our window size == k, then we do the calculations - 
        // In this case add the first negative integer if present or else add 0.
        else if((j - i + 1) == k){
            // Using calculations finding the answer.
            // if no element in the list denotes no negative element in the subarray. So insert 0.
            if(negative.size() == 0) ans.push_back(0);
            // or else the first negative element of the subarray will be present at 
            // the front of the list.
            else ans.push_back(negative.front());
            // Sliding the Window ahead.
            // While sliding we have to remove the calculations we did for the current start element of the 
            // subarray. In this case if it was negative element we pushed it into the list. so we have
            // to remove it now.
            if(arr[i] < 0) negative.pop_front();
            i++, j++; // Maintaining the size of the window..
        }
    } 
    return ans;
 }