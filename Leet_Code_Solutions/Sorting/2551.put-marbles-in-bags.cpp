#define ll long long int
class Solution {
public:
    
    long long putMarbles(vector<int>& weights, int k) {
        // Here we have to make k partitions of the array. 
        // And among them find two partitions in which the 
        // score is maximum and minimum.
        
        // for that we have to create partitions array and store every consecutive edge sum.
        // As the time complexity of the dp approach will give time limit exceeded.
        int n = weights.size();
        vector<int> contributions(n - 1, 0);
        for(int i = 1;i < weights.size();i++){
            contributions[i - 1] = (weights[i] + weights[i - 1]);
        }
        sort(contributions.begin(), contributions.end());
        long long int maxScore = weights[0] + weights[n - 1];
        long long int minScore = weights[0] + weights[n - 1];
        
        for(int i = 0;i < (k - 1);i++) minScore += contributions[i];
        for(int i = n - 2;i > (n - k - 1);i--) maxScore += contributions[i];
        
        return (maxScore - minScore);
    }
};