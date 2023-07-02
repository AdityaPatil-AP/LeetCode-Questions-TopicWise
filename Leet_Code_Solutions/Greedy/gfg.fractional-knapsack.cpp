class Solution
{
    public:
    static bool comp(struct Item &i1, struct Item &i2){
        double v1 = (double)i1.value/(double)i1.weight;
        double v2 = (double)i2.value/(double)i2.weight;
        if(v1 > v2) return true;
        return false;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans = 0;
        sort(arr, arr + n, comp);
        
        for(int i = 0;i < n;i++){
            if(W > 0){
                if(W > arr[i].weight){
                    W -= arr[i].weight;
                    ans += arr[i].value;
                }
                else{
                    ans += ((double)arr[i].value/arr[i].weight) * (double)W;
                    W = 0;
                }
            }
        }
        return ans;
    }
        
};