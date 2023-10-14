class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;

        // we will put the maximum frequency character first.
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string ans = "";
        while (pq.size() > 1)
        {
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();

            // Add two chars of top.
            if (one.first >= 2)
            {
                ans += one.second;
                ans += one.second;
                one.first -= 2;
            }
            else
            {
                ans += one.second;
                one.first -= 1;
            }

            // For the second highest frequency character we will add two if
            // it's frequency greater than the first one.
            if (two.first >= 2 && two.first >= one.first)
            {
                ans += two.second;
                ans += two.second;
                two.first -= 2;
            }
            else
            {
                ans += two.second;
                two.first -= 1;
            }

            if (one.first > 0)
                pq.push(one);
            if (two.first > 0)
                pq.push(two);
        }

        if (pq.size() > 0)
        {
            if (pq.top().first >= 2)
            {
                ans += pq.top().second;
                ans += pq.top().second;
            }
            else
            {
                ans += pq.top().second;
            }
        }

        return ans;
    }
};