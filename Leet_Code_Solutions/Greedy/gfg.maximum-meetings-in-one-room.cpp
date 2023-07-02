class Solution{
public:
    
    static bool comp(vector<int> &meeting1, vector<int> &meeting2){
        if(meeting1[2] < meeting2[2]) return true;
        if(meeting1[2] == meeting2[2]){
            if(meeting1[0] < meeting2[0]) return true;
            return false;
        }
        return false;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>> arr(N, vector<int>(3, 0));
        for(int i = 0;i < N;i++){
            arr[i][0] = i + 1; // Indication of my index.
            arr[i][1] = S[i]; // Storing Starting Time
            arr[i][2] = F[i]; // Storing Ending Time.
        }
        sort(arr.begin(), arr.end(), comp);
        vector<int> ans;
        ans.push_back(arr[0][0]);
        int end = arr[0][2];
        for(int i = 1;i < N;i++){
            if(arr[i][1] > end){
                ans.push_back(arr[i][0]);
                end = arr[i][2];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};