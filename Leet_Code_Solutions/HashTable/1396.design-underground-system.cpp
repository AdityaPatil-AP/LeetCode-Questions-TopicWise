class UndergroundSystem
{
private:
    map<int, pair<string, int>> nameToStation;
    map<pair<string, string>, pair<int, int>> stationToTime;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        nameToStation[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        string stationName1 = nameToStation[id].first;
        int time1 = nameToStation[id].second;
        stationToTime[{stationName1, stationName}].first += (t - time1);
        stationToTime[{stationName1, stationName}].second += 1;
    }

    double getAverageTime(string s, string e)
    {
        double ans = ((double)stationToTime[{s, e}].first / stationToTime[{s, e}].second);
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */