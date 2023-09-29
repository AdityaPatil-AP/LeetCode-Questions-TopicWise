// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class a{
    public:
    int add(int a, int b){
        cout << "Inside a" << endl;
        return a + b;
    }
};

class b : public a{
    public:
    int add(int a, int b){
        cout << "Inside b" << endl;
        return a + b;
    }
};

int main() {
    // Write C++ code here
    int (a::*funcPtr1)(int, int) = &a::add;
    int (b::*funcPtr2)(int, int) = &b::add;
    
    a obj1;
    b obj2;
    
    cout << funcPtr1 << endl;
    cout << funcPtr2 << endl;
    
    cout << (obj1.*funcPtr1)(5, 10) << endl;
    cout << (obj2.*funcPtr2)(5, 10) << endl;
    
    return 0;
}