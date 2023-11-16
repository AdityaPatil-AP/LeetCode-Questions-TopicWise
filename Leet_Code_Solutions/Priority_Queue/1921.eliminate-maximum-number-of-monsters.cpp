class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> arrival;
        int n = dist.size();

        for(int i = 0;i < n;i++){
            arrival.push_back((float) dist[i]/speed[i]);
        }

        sort(arrival.begin(), arrival.end());

        int ans = 0;

        for(int i = 0;i < n;i++){
            if(i >= arrival[i]){
                break;
            }

            ans++;
        }

        return ans;

        // Using Priority Queue.
        // double t = 0;
        // priority_queue<double, vector<double>, greater<double>> pq;

        // int n = dist.size();
        // for(int i = 0;i < n;i++){
        //     double timeToReach = (double)dist[i]/speed[i];
        //     pq.push(timeToReach);
        // }

        // int ans = 0;
        // while(pq.size() > 0){
        //     double time = pq.top();
        //     pq.pop();

        //     if(t < time) ans++;
        //     else return ans;

        //     t += 1;
        // }

        // return ans;
    }
};