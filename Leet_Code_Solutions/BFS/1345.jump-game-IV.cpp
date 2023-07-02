class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;
        if (arr.size() == 2)
            return 1;
        unordered_map<int, priority_queue<int>> graph;
        for (int i = 0; i < arr.size(); i++)
        {
            graph[arr[i]].push(i);
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, arr[0]}});
        unordered_map<int, bool> vis;
        vis[0] = true;
        int ans = INT_MAX;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int cost = cur.first;
            int index = cur.second.first;
            int value = cur.second.second;
            if (index == arr.size() - 1)
            {
                ans = min(ans, cost);
                continue;
            }
            if (index - 1 >= 0 && !vis[index - 1])
            {
                q.push({cost + 1, {index - 1, arr[index - 1]}});
                vis[index - 1] = true;
            }
            if (index + 1 < arr.size() && !vis[index + 1])
            {
                q.push({cost + 1, {index + 1, arr[index + 1]}});
                vis[index + 1] = true;
            }

            while (!graph[value].empty())
            {
                int cur = graph[value].top();
                graph[value].pop();
                if (!vis[cur] && index != cur)
                {
                    q.push({cost + 1, {cur, arr[cur]}});
                    vis[cur] = true;
                }
            }
        }

        return ans;
    }
};
