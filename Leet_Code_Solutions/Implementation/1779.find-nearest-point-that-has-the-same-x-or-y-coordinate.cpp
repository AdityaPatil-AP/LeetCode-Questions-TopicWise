class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int mini = INT_MAX;
        for(int i = 0;i < points.size();i++){
            if(x == points[i][0]){
                if(abs(y - points[i][1]) < mini){
                    ans = i;
                    mini = abs(y - points[i][1]);
                }
            }
            else if(y == points[i][1]){
                if(abs(x - points[i][0]) < mini){
                    ans = i;
                    mini = abs(x - points[i][0]);
                }
            }
        }
        return ans;
    }
};