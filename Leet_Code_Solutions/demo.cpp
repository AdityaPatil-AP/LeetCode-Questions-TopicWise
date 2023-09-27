#include <iostream>
#include <thread>
#include <unistd.h>
#include "demo1.cpp"

using namespace std;

void taskA()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("Task A : %d \n", i);
        fflush(stdout);
    }
}

void taskB()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("Task B : %d\n", i);
        fflush(stdout);
    }
}

int main()
{
    // thread t1(taskA);
    // thread t2(taskB);

    // t2.join();
    // t1.join();

    extern int a;
    cout << a << endl;
    return 0;
}