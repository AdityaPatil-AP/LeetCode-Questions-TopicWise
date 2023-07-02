class Solution 
{
    public:
    
    static bool comp(struct Job &j1, struct Job &j2){
        return (j1.profit > j2.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // For maximum profit, sorting the Jobs in Descending order of the Profit.
        sort(arr, arr + n, comp);
        // find the maximum deadline.
        int maxi = arr[0].dead;
        for(int i = 0;i < n;i++){
            maxi = max(maxi, arr[i].dead);
        }
        
        // Create the array to store the jobs selected by us on that day.
        int slot[maxi + 1];
        // Currently all slots are empty
        for(int i = 0;i <= maxi;i++){
            slot[i] = -1;
        }
        int numJobs = 0, ans = 0;
        for(int i = 0;i < n;i++){
            int deadline = arr[i].dead;
            for(int j = deadline;j >= 1;j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    ans += arr[i].profit;
                    numJobs++;
                    break;
                }
            }
        }
        return {numJobs, ans};
    } 
};