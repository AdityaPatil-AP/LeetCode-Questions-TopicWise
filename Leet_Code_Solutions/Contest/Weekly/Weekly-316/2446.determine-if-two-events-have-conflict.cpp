class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // My method of Converting Hours and Minutes into minutes and then doing comparision.
        // int startTime1, endTime1, startTime2, endTime2;
        // startTime1 = (10 * (event1[0][0] - '0') + (event1[0][1] - '0')) * 60 + (event1[0][3] - '0') * 10 + (event1[0][4] - '0');
        // endTime1 = (10 * (event1[1][0] - '0') + (event1[1][1] - '0')) * 60 + (event1[1][3] - '0') * 10 + (event1[1][4] - '0');
        // startTime2 =  (10 * (event2[0][0] - '0') + (event2[0][1] - '0')) * 60 + (event2[0][3] - '0') * 10 + (event2[0][4] - '0');
        // endTime2 = (10 * (event2[1][0] - '0') + (event2[1][1] - '0')) * 60 + (event2[1][3] - '0') * 10 + (event2[1][4] - '0');
        // // cout << startTime1 << " " << endTime1 << 
        // if(startTime1 > endTime2 || startTime2 > endTime1){
        //     return false;
        // }
        // return true;
        
        // Similarly this can easily be done using string Comparision.
        return (event1[0] >= event2[0] && event1[0] <= event2[1]) || (event2[0] >= event1[0] && event2[0] <= event1[1]);
    }
};