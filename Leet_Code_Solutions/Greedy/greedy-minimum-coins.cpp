#include <bits/stdc++.h>
using namespace std;

vector<int> ans1;
int solve(int value){
    int denominations[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans = 0;
    for(int i = 8;i >= 0;i--){
        while(denominations[i] <= value){
            value -= denominations[i];
            ans++;
            ans1.push_back(denominations[i]);
        }
    }
    return ans;
}

int main(){
    int value;
    cin >> value;
    cout << solve(value) << endl;
    for(int i = 0;i < ans1.size();i++){
        cout << ans1[i] << " ";
    }
    cout << endl;
    return 0;
}