class Solution
{
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        //         int distance = 0;
        //         while(mainTank >= 5){
        //             mainTank -= 5;
        //             if(additionalTank > 0){
        //                 additionalTank--;
        //                 mainTank += 1;
        //             }

        //             distance += 50;
        //         }

        //         if(mainTank > 0){
        //             distance += (10 * mainTank);
        //         }

        //         return distance;

        // Suppose we have transferred x litres from AT to MT.

        // x <= AT
        // MT + x > 5x.

        // 4x < MT.
        // for equality, x <= (MT - 1)/4 for integer division.

        int ans = mainTank + min((mainTank - 1) / 4, additionalTank);

        return (ans * 10);
    }
};