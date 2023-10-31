class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int trials = minutesToTest / minutesToDie;

        // It can die on which trial.
        int outcomes = trials + 1;

        int i = 0;

        while (pow(outcomes, i) < buckets)
        {
            i++;
        }
        return i;
    }
};