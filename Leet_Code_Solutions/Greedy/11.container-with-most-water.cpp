class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxarea = INT_MIN;
        while(i < j){
            int distance = (j - i);
            int h = min(height[i], height[j]);
            if((distance * h) > maxarea){
                maxarea = (distance * h);
            }
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxarea;
    }
};