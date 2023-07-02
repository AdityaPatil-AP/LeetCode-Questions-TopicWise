class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int fr)
    {
        int size = flowerbed.size();

        int flowersPlanted = 0;

        for (int i = 0; i < size; i++)
        {
            // If the current plot is empty.
            if (flowerbed[i] == 0)
            {
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                // If both adjacent plots are empty, then plant one here.
                if (leftEmpty && rightEmpty)
                {
                    flowerbed[i] = 1;
                    flowersPlanted++;
                    if (flowersPlanted >= fr)
                    {
                        return true;
                    }
                }
            }
        }

        return (flowersPlanted >= fr);
    }
};