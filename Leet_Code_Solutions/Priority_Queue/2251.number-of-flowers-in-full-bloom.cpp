struct myComp
{
    constexpr bool operator()(
        vector<int> &v1, vector<int> &v2)
        const noexcept
    {
        if (v1[1] < v1[2])
        {
            return true;
        }
        else if (v1[1] == v2[1])
        {
            return (v1[0] <= v2[0]);
        }

        return false;
    }
};

class Solution
{
public:
    static bool compareT(vector<int> &v1, vector<int> &v2)
    {
        if (v1[1] < v1[2])
        {
            return true;
        }
        else if (v1[1] == v2[1])
        {
            return (v1[0] <= v2[0]);
        }

        return false;
    }

    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {

        // This will be Sorted by starting time and then by ending time.
        // But I want the reverse thing to happen
        priority_queue<int, vector<int>, greater<int>> pq;

        vector<int> ans;

        // pq -> denotes the numbers of flowers that are blooming when the ith person
        // arrives.
        int n = people.size();

        int j = 0; // Tracker to current flower in flowers array.
        sort(flowers.begin(), flowers.end());
        unordered_map<int, int> mp;
        vector<int> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end());
        int m = flowers.size();

        for (int i = 0; i < n; i++)
        {
            int arrivalTime = sortedPeople[i];

            // Adding the flowers in the range of arrival time.
            while (j < m && arrivalTime >= flowers[j][0])
            {
                pq.push(flowers[j][1]);
                j++;
            }

            // Removing the flowers from the priority queue.
            while (pq.size() > 0 && pq.top() < arrivalTime)
            {
                pq.pop();
            }

            mp[arrivalTime] = pq.size();
        }

        for (int i = 0; i < n; i++)
        {
            ans.push_back(mp[people[i]]);
        }

        return ans;
    }
};