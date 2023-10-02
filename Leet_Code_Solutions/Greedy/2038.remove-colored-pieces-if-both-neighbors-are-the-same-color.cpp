class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int moves_a = 0;
        int moves_b = 0;

        int n = colors.size();
        int i = 0;

        while (i < n)
        {
            int curr_a = 0;
            while (i < n && colors[i] == 'A')
            {
                curr_a++;
                i++;
            }

            moves_a += (curr_a > 2) ? curr_a - 2 : 0;

            int curr_b = 0;

            while (i < n && colors[i] == 'B')
            {
                curr_b++;
                i++;
            }

            moves_b += (curr_b > 2) ? curr_b - 2 : 0;
        }

        return (moves_a > moves_b);
    }
};