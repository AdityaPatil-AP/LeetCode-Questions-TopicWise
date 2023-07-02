//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        // We have been given a window size of k.
        // Currently we have a window size = (j - i + 1) of 1, as i = 0 and j = 0.
        int i = 0, j = 0; // Here i = denotes start of the window
        // j = denotes the end of the window.
        long mx = INT_MIN;
        // Will store the sum of the window.
        long sum = 0;
        while(j < arr.size()){
            // including the current element.
            sum += arr[j];
            // If window size is less than the given size we increment the size of the window.
            // As well as we are including that element in the sum.
            if((j - i + 1) < k){
                j++;
            }
            // If the window size is equal to required window size then we have to just maintain 
            // the window size.
            else if((j - i + 1) == k){
                // Now we update the max sum subarray if this is subarray with the maximum sum till now.
                mx = max(sum, mx);
                // Maintaining the window size..
                sum -= arr[i];
                i++, j++;
            }
        }
        // mx will contain the maximum sum of all subarrays at the end.
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends

