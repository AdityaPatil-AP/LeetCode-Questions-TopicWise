#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

int minimumPeople(int n, int arr[], int dep[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i], 1});
        pq.push({dep[i], -1});
    }

    int ans = 0;
    int curr = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        curr += top.second;

        ans = max(ans, curr);
    }

    return ans;
}

int main()
{
    vector<vector<int>> people = {{1, 3}, {2, 7}, {6, 9}};
    cout << minimumPeople(people, 3) << endl;

    return 0;
}
