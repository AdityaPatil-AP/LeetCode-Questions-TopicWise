#include <bits/stdc++.h>
class Solution
{
public:
    // Using Brute Force
    // string longestCommonPrefix(vector<string>& strs) {
    //     int ans = -1;
    //     int minsize = 201;
    //     // Finding the minimum size.
    //     for(auto str : strs){
    //         int n = str.size();
    //         minsize = min(n, minsize);
    //     }
    //     bool flag = true;
    //     for(int i = 0;i < minsize;i++){
    //         char character = strs[0][i];
    //         for(int j = 1;j < strs.size();j++){
    //             if(strs[j][i] == character){
    //                 continue;
    //             }
    //             else { flag= false;break;}
    //         }
    //         if(!flag) break;
    //         ans++;
    //     }
    //     string res;
    //     for(int i = 0;i <= ans;i++)
    //         res += strs[0][i];
    //     return res;
    // }

    // Using Sort
    // string longestCommonPrefix(vector<string> &strs){
    //     sort(strs.begin(), strs.end());
    //     int n = strs.size();
    //     string a = strs[0], b = strs[n - 1];
    //     int minsize = min(a.size(), b.size());
    //     string ans = "";
    //     for(int i = 0;i < minsize;i++){
    //         if(a[i] == b[i]){
    //             ans += a[i];
    //         }else break;
    //     }
    //     return ans;
    // }
};