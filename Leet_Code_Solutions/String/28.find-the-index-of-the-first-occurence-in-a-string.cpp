class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // Brute force.
        // For every index i of haystack, we will compare the needle starting from ith index of haystack.
        // If we find it then return the index or return -1.
        // for(int i = 0;i < haystack.size();i++){
        //     bool ans = true;
        //     for(int j = 0;j < needle.size();j++){
        //         if(i + j < haystack.size() && needle[j] == haystack[i + j]){
        //             continue;
        //         }else ans = false;
        //     }
        //     if(ans) return i;
        // }
        // return -1;

        // Optimised One uses KMP Algorithm. Time Complexity is O(m + n).
        // It does some pre-processing.
    }
};