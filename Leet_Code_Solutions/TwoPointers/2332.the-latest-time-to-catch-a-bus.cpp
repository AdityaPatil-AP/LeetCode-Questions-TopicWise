class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &b, vector<int> &p, int cap)
    {
        // Greedy + Two Pointers + Binary Search

        //         sort(buses.begin(), buses.end());
        //         sort(passengers.begin(), passengers.end());
        //         int n = buses.size();
        //         int m = passengers.size();
        //         set<int> st;
        //         int j = 0;
        //         bool full = false;
        //         for(int i = 0;i < n;i++){
        //             int cp = capacity;
        //             int departure = buses[i];
        //             while(j < m && passengers[j] <= departure && cp > 0){
        //                 st.insert(passengers[j]);
        //                 cp--;
        //                 j++;
        //             }
        //             if(i == n - 1 && cp == 0) full = true;
        //         }

        //         int ans;
        //         if(full) ans = passengers[j - 1];
        //         else ans = buses[n - 1];
        //         while(st.count(ans)){
        //             ans--;
        //         }
        //         return ans;

        //         int n = buses.size();
        //          sort(buses.begin(),buses.end());
        //          unordered_set<int> st;
        //         priority_queue<int,vector<int>,greater<int>> pq;
        //         for(auto &it : passengers){
        //             pq.push(it);
        //         }

        //         int val = capacity;
        //         for(int i = 0;i<n;i++){
        //             val = capacity;
        //             if(i == n-1){
        //                 while(!pq.empty() && pq.top()<=buses[i] && val>1){
        //                         st.insert(pq.top());
        //                         pq.pop();
        //                         val--;
        //                 }
        //                 int latestTime = 0;
        //                 if(pq.empty()==true)
        //                 latestTime = buses[i];
        //                 else
        //                     latestTime = min(buses[i],pq.top()-1);
        //                 while(st.count(latestTime)>0)
        //                     latestTime--;
        //                 return latestTime;
        //             }
        //             while(!pq.empty() && pq.top()<=buses[i] && val){
        //                 st.insert(pq.top());
        //                 pq.pop();
        //                 val--;
        //             }
        //         }
        // return 0;

        sort(begin(b), end(b));
        sort(begin(p), end(p));
        int i = 0, j = 0, start = 0;
        while (i < b.size() - 1 && j < p.size())
            if (p[j] <= b[i] && j - start < cap)
                ++j;
            else
            {
                ++i;
                start = j;
            }
        while (j < p.size() && p[j] <= b.back() && cap)
        {
            ++j;
            --cap;
        }
        int latest = cap ? b.back() : p[j - 1];
        for (j = j - 1; j >= 0 && latest == p[j]; --j)
            latest = p[j] - 1;
        return latest;
    }
};