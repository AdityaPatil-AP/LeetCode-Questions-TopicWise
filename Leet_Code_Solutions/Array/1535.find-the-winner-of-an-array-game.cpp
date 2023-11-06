class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int max_element = arr[0];
        queue<int> q;
        for (int i = 1; i < arr.size(); i++)
        {
            max_element = max(arr[i], max_element);
            q.push(arr[i]);
        }

        int curr = arr[0];
        int winstreak = 0;

        while (!q.empty())
        {
            int opponent = q.front();
            q.pop();

            if (curr > opponent)
            {
                q.push(opponent);
                winstreak++;
            }
            else
            {
                q.push(curr);
                curr = opponent;
                winstreak = 1;
            }

            if (winstreak == k || curr == max_element)
            {
                return curr;
            }
        }

        return -1;
    }
};