class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        // Using binary Search.
        // int low = 0, high = letters.size() - 1;
        // while(low <= high){
        //     int mid = low + (high - low)/2;
        //     if(target < letters[mid]){
        //         if(mid == 0){
        //             return letters[mid];
        //         }
        //         if(target >= letters[mid - 1]){
        //             return letters[mid];
        //         }
        //         high = mid - 1;
        //     }
        //     else if(target >= letters[mid]){
        //         low = mid + 1;
        //     }
        // }
        // return letters[0];

        //         int l = 0, r = letters.size();

        //         while(l < r){
        //             int mid = (l + (r - l)/2);

        //             if(letters[mid] <= target){
        //                 l = mid + 1;
        //             }
        //             else{
        //                 r = mid;
        //             }
        //         }

        //         if(l == letters.size()) return letters[0];

        //         return letters[l];

        // Using upperbound.

        auto it = upper_bound(letters.begin(), letters.end(), target);

        if (distance(it, letters.end()) == 0)
        {
            return letters[0];
        }
        else
        {
            return letters[it - letters.begin()];
        }
    }
};