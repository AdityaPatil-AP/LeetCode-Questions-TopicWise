class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // Brute Force
        int number = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            while (arr[i] != number)
            {
                if (k == 1)
                    return number;
                k--;
                number++;
            }
            if (arr[i] == number)
            {
                number++;
            }
        }
        return (number + k - 1);
    }
};