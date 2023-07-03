class Solution
{
public:
    bool allZero(vector<int> &people)
    {
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i] != 0)
                return false;
        }
        return true;
    }

    int find(int index, int n, vector<vector<int>> &requests, vector<int> &people, int changes)
    {
        if (index == requests.size())
        {
            if (changes != 0 && allZero(people))
            {
                return __builtin_popcount(changes);
            }
            else
            {
                return 0;
            }
        }

        // For the current request we have the option to choose and not choose.
        people[requests[index][0]] -= 1;
        people[requests[index][1]] += 1;

        int ans = find(index + 1, n, requests, people, (changes | (1 << index)));

        people[requests[index][0]] += 1;
        people[requests[index][1]] -= 1;

        ans = max(ans, find(index + 1, n, requests, people, changes));

        return ans;
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        // When we have to explore all the ways then have to use
        // backtracking for sure.

        vector<int> people(n, 0); // tracks the changes of people in building.

        // Arguments -> index, total buildings, requests, track of people in building, int
        // changes.
        int ans = find(0, n, requests, people, 0);

        return ans;
    }
};