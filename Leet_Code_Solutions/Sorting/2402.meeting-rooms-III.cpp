class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        // vector<long long> roomAvailabilityTime(n, 0);
        // vector<int> meetingCount(n, 0);
        // sort(meetings.begin(), meetings.end());

        // for (auto& meeting: meetings) {
        //     int start = meeting[0], end = meeting[1];
        //     long long minRoomAvailabilityTime = LLONG_MAX;
        //     int minAvailableTimeRoom = 0;
        //     bool foundUnusedRoom = false;

        //     for (int i = 0; i < n; i++) {
        //         if (roomAvailabilityTime[i] <= start) {
        //             foundUnusedRoom = true;
        //             meetingCount[i]++;
        //             roomAvailabilityTime[i] = end;
        //             break;
        //         }

        //         if (minRoomAvailabilityTime > roomAvailabilityTime[i]) {
        //             minRoomAvailabilityTime = roomAvailabilityTime[i];
        //             minAvailableTimeRoom = i;
        //         }
        //     }

        //     if (!foundUnusedRoom) {
        //         roomAvailabilityTime[minAvailableTimeRoom] += end - start;
        //         meetingCount[minAvailableTimeRoom]++;
        //     }
        // }
        // int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        // for (int i = 0; i < n; i++) {
        //     if (meetingCount[i] > maxMeetingCount) {
        //         maxMeetingCount = meetingCount[i];
        //         maxMeetingCountRoom = i;
        //     }
        // }
        // return maxMeetingCountRoom;

        // First we require an array to store the number of times a meeting happened in
        // that particular room.
        // Another array will be required to note the time after which the every room will
        // be available if it is being used.
        vector<int> meetingCount(n, 0);
        vector<long long> roomAvailableTime(n, 0);
        sort(meetings.begin(), meetings.end());

        // Sort the meetings on the basis of starting time.
        for (auto &meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];

            int minimumAvailableRoom = 0;
            long long minimumAvailableTimeRoom = LLONG_MAX;
            bool foundUnusedRoom = false;

            for (int i = 0; i < n; i++)
            {
                if (start >= roomAvailableTime[i])
                {
                    roomAvailableTime[i] = end;
                    meetingCount[i]++;
                    foundUnusedRoom = true;
                    break;
                }

                if (minimumAvailableTimeRoom > roomAvailableTime[i])
                {
                    minimumAvailableTimeRoom = roomAvailableTime[i];
                    minimumAvailableRoom = i;
                }
            }

            if (!foundUnusedRoom)
            {
                roomAvailableTime[minimumAvailableRoom] += (end - start);
                meetingCount[minimumAvailableRoom]++;
            }
        }

        int maxMeeting = 0, maxMeetingRoom = 0;

        for (int i = 0; i < n; i++)
        {
            if (maxMeeting < meetingCount[i])
            {
                maxMeeting = meetingCount[i];
                maxMeetingRoom = i;
            }
        }

        return maxMeetingRoom;
    }
};