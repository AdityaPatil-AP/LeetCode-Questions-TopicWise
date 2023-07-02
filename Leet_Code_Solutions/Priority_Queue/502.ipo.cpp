class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // Choose as much projects as you can.
        // But choose them greedily as those which give us maximum profit and should
        // be available(our capital is enough to start the project).

        // When we are unable to solve the problem. Break the problem into smaller sub-problems.
        // Like here we took the case of k == 1, and we found out that greedily we will the choose
        // the most profitable and available project. If no such project is there then the answer is 0.

        // It can be generalised for any arbitrary k. First we will choose the most profitable and available
        // project. Thus our capital increases and now more projects our available to be started.

        // But why to choose most profitable?? If we choose a less profitable project, then our capital is less
        // therefore less projects are available to be started. That's why we always choose the most profitable one.

        // We repeat this process of choosing the most profitable available project and then updating the
        // projects we can afford until we finish k projects or cannot afford any new project.

        // Now the problem breaks into two parts - 1) finding the new available projects after finishing the previous
        // one and
        // 2) finding the most profitable available project.

        // For first part we will sort the array by capital values in ascending order as smaller project will be
        // available sooner.
        // We will keep a pointer to first unavailable project till now.
        // As we get more money, we will keep on unlocking more projects.

        // For the second part, from the available ones we have to find the most profitable project.
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++)
        {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int ptr = 0; // points to the currently unavailable project.

        for (int i = 0; i < k; i++)
        {
            while (ptr < n && projects[ptr].first <= w)
            {
                pq.push(projects[ptr++].second);
            }
            if (pq.empty())
            {
                break;
            }
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};