class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// Sort the arrival and the departure times.
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int i = 1, j = 0, res = 1;
    	int platform = 1;
    	while(i < n){
    	    if(arr[i] <= dep[j]){
    	        platform++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]){
    	        platform--;
    	        j++;
    	    }
    	    if(platform > res){
    	        res = platform;
    	    }
    	}
    	return res;
    }
};