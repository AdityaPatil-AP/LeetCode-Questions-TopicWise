class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        // Using Binary Search and accumulate.
        //         int aliceTotal = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        //         int bobTotal = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        //         sort(aliceSizes.begin(), aliceSizes.end());
        //         sort(bobSizes.begin(), bobSizes.end());

        //         if(aliceTotal > bobTotal){
        //             int diff = aliceTotal - bobTotal;

        //             for(int i = 0;i < bobSizes.size();i++){
        //                 int curr = bobSizes[i];
        //                 int toFind = curr + diff/2;

        //                 if(find(aliceSizes, toFind)){
        //                     return {toFind, curr};
        //                 }
        //             }
        //         }
        //         else{
        //             int diff = bobTotal - aliceTotal;

        //             for(int i = 0;i < aliceSizes.size();i++){
        //                 int curr = aliceSizes[i];
        //                 int toFind = curr + diff/2;

        //                 if(find(bobSizes, toFind)){
        //                     return {curr, toFind};
        //                 }
        //             }
        //         }

        //         return {-1, -1};

        // Using Set.
        int aliceTotal = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobTotal = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        set<int> bobElem;
        for (int i = 0; i < bobSizes.size(); i++)
        {
            bobElem.insert(bobSizes[i]);
        }

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            int toFind = (bobTotal - aliceTotal) / 2 + aliceSizes[i];
            if (bobElem.find(toFind) != bobElem.end())
                return {aliceSizes[i], toFind};
        }

        return {-1, -1};
    }

    bool find(vector<int> &arr, int num)
    {
        int l = 0, r = arr.size();

        while (l < r)
        {
            int mid = (l + (r - l) / 2);

            if (arr[mid] == num)
            {
                return true;
            }

            if (arr[mid] < num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return false;
    }
};