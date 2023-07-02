struct meeting{
    int s;
    int e;
    int index;
}typedef meeting;

class Solution
{
    public:
    
    static bool comp(meeting &m1, meeting &m2){
        if(m1.e < m2.e) return true;
        if(m1.e > m2.e) return false;
        if(m1.index < m2.index) return true;
        return false;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<meeting> meet(n, {0, 0, 0});
        for(int i = 0;i < n;i++){
            meet[i].s = start[i];
            meet[i].e = end[i];
            meet[i].index = i + 1;
        }
        sort(meet.begin(), meet.end(), comp);
        int endTime = meet[0].e;
        int ans = 1;
        for(int i = 1;i < n;i++){
            if(endTime < meet[i].s){
                ans++;
                endTime = meet[i].e;
            }
        }
        return ans;
    }
};