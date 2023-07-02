#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int countSubs(string &word)
{
    int subs = 0;
    for (int i = 1; i < word.size(); i++)
    {
        if (word[i] == word[i - 1])
        {
            word[i] = ' ';
            subs++;
        }
    }
    return subs;
}

vector<int> getPrefixScores(vector<int> &arr)
{
    vector<int> answer;
    int n = arr.size();

    vector<ll> prefixSum(n);
    vector<ll> totalSum(n);
    totalSum[0] = arr[0];
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
        totalSum[i] = prefixSum[i] + totalSum[i - 1];
    }

    priority_queue<ll> pq;
    for (int k = 1; k <= n; k++)
    {

        pq.push(arr[k - 1]);

        ll maxnum = pq.top();
        ll sum = totalSum[k - 1] + (maxnum * k);

        sum = sum % mod;
        answer.push_back(sum);
    }

    return answer;
}

// #define ll long long int
// #define mod 1000000007

// vector<int> getPrefixScores(vector<int> &arr)
// {
//     vector<int> answer;
//     int n = arr.size();
//     multiset<ll> prefixSet; // Using multiset instead of priority_queue
//     ll prefixSum = 0;
//     for (int k = 1; k <= n; k++)
//     {
//         prefixSet.insert(arr[k - 1]);
//         prefixSum += arr[k - 1];

//         ll sum = 0;
//         for (auto it = prefixSet.rbegin(); it != prefixSet.rend(); ++it)
//         {
//             sum += prefixSum;
//             prefixSum -= *it;
//         }

//         sum = sum % mod;
//         answer.push_back(sum);
//     }

//     return answer;
// }

int countValidKeys(long long num)
{
    long long m = 1;
    while (m * m <= num)
    {
        m++;
    }

    return (m - 2);
}

vector<int> helper(vector<long long> keys)
{
    vector<int> ans;
    for (int i = 0; i < keys.size(); i++)
    {
        ans.push_back(countValidKeys(keys[i]));
    }

    return ans;
}

int main()
{
    // vector<int> words = {1, 2, 1};
    // vector<int> ans = getPrefixScores(words);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    vector<long long> keys = {10000003, 10382, 381835151435213, 1384813281, 1341351315342};
    vector<int> count = helper(keys);

    for (auto i : count)
    {
        cout << i << endl;
    }
    return 0;
}