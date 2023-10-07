#include <iostream>

using namespace std;

int main()
{
    
    int var1 = 40, var2 = 80;
    try
    {
        cin >> var1 >> var2;
        if (var2 == 0)
            throw var2;
        else
            cout << var2 % var1;
    }
    catch (exception e)
    {
    }

    return 0;
}