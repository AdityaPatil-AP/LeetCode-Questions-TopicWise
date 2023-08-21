
using namespace std;
#include <bits/stdc++.h>
bool comp(int &a, int &b)
{
    if (a % 2 == 0 && b % 2 == 1)
    {
        return true;
    }
    if (a % 2 == 0 && b % 2 == 0 && a <= b)
    {
        return true;
    }
    return false;
}

vector<int> funcArrange(vector<int> inputArr)
{
    sort(inputArr.begin(), inputArr.end(), comp);

    return inputArr;
}

int main()
{
    return 0;
}