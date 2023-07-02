class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        // Sorting and Greedy.
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        // I will check for every player whether he can get a trainer. If yes then match it.
        int n = players.size();
        int m = trainers.size();
        // i -> players array.
        // j -> trainers array.
        int match = 0;
        for (int i = 0, j = 0; i < n && j < m; i++)
        {
            while (j < m)
            {
                if (trainers[j] >= players[i])
                {
                    match++;
                    j++;
                    break;
                }
                j++;
            }
        }

        return match;
    }
};