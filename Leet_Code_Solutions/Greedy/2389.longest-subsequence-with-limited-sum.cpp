class Solution
{
public:
    vector<int> answerQueries(vector<int> A, vector<int> &queries)
    {
        // sort(A.begin(), A.end());
        // vector<int> res;
        // for (int i = 1; i < A.size(); ++i)
        //     A[i] += A[i - 1];
        // for (int& q: queries)
        //     res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin());
        // return res;
        // Sorting + Greedy.
        sort(A.begin(), A.end());
        vector<int> res;
        // Prefix Sum.
        for (int i = 1; i < A.size(); ++i)
        {
            A[i] += A[i - 1];
        }
        // Binary Search in form of upper_bound.
        for (int &q : queries)
        {
            res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin());
        }
        return res;
    }
};