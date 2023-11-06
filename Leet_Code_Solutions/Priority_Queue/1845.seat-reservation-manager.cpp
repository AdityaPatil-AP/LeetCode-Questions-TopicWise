class SeatManager
{
public:
    int toReserve = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    // set will keep the log of reserved seats.
    // pq will store the smallest-numbered unreserved seat at the top.
    set<int> st;
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            pq.push(i);
        }
    }

    int reserve()
    {
        int smallestSeat = pq.top();
        pq.pop();

        return smallestSeat;
    }

    void unreserve(int seatNumber)
    {
        // Remove this reserved seat.
        pq.push(seatNumber);
    }
};
