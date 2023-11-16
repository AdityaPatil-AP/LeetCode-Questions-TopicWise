#include <bits/stdc++.h>
using namespace std;

int main()
{
    bitset<8> num("1111");
    unsigned long val = num.to_ulong();
    cout << val << endl;
}