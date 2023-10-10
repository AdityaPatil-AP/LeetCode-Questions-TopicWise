#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

pair<int, int> getReducedForm(int dy, int dx)
{
    int g = gcd(abs(dy), abs(dx));

    bool sign = (dy < 0) ^ (dx < 0);

    if (sign)
    {
        return {-abs(dy) / g, abs(dx) / g};
    }
    else
    {
        return {abs(dy) / g, abs(dx) / g};
    }
}

int minLinesToCoverPoints(int points[][2], int N, int x0, int y0)
{
    // set to store slope as a pair.
    set<pair<int, int>> st;
    pair<int, int> temp;

    int minLines = 0;

    // loop over all points once.
    for (int i = 0; i < N; i++)
    {
        // get x and y coordinate of the current point.
        int curX = points[i][0];
        int curY = points[i][1];

        temp = getReducedForm(curY - y0, curX - x0);

        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            minLines++;
        }
    }

    return minLines;
}

int main()
{
    int x0, y0;
    x0 = 1;
    y0 = 0;

    int points[][2] =
        {
            {-1, 3},
            {4, 3},
            {2, 1},
            {-1, -2},
            {3, -3}};

    int N = sizeof(points) / sizeof(points[0]);

    cout << minLinesToCoverPoints(points, N, x0, y0) << endl;
}