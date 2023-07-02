class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int low = 0, high = height.size() - 1;
        int maxArea = INT_MIN;
        while (low < high)
        {
            maxArea = max(maxArea, (high - low) * min(height[low], height[high]));
            if (height[low] > height[high])
                high--;
            else
                low++;
        }
        return maxArea;
    }
};