class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        double t = 0;
        priority_queue<double, vector<double>, greater<double>> pq;

        int n = dist.size();
        for(int i = 0;i < n;i++){
            double timeToReach = (double)dist[i]/speed[i];
            pq.push(timeToReach);
        }

        int ans = 0;
        while(pq.size() > 0){
            double time = pq.top();
            pq.pop();

            if(t < time) ans++;
            else return ans;

            t += 1;
        }

        return ans;
    }
};