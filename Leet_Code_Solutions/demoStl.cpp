#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    int basic[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }

    cout << "Element at 2nd Index " << a.at(2) << endl;

    cout << "Empty or not " << a.empty() << endl;

    cout << "First element " << a.front() << endl;

    cout << "Last element " << a.back() << endl;

    // Vector is Dynamic Array.
    cout << "Vector : " << endl;
    vector<int> v;

    cout << "Size : " << v.capacity() << endl;
}