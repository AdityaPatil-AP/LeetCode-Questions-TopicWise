class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        // int ans = 0;

        // int n = nums.size();
        // unordered_map<int, int> mp;
        // priority_queue<int> pq;
        // unordered_set<int> st;
        // for(int i = 0;i < n;i++){
        //     if(st.find(nums[i]) == st.end()){
        //         pq.push(nums[i]);
        //     }
        //     st.insert(nums[i]);
        //     mp[nums[i]]++;
        // }

        // while(!pq.empty()){
        //     int curr = pq.top();
        //     pq.pop();

        //     int count = mp[curr];

        //     int operations = pq.size() * count;

        //     ans += operations;
        // }

        // return ans;

        // Using Sort and Count.
        sort(nums.begin(), nums.end());

        int ans = 0;
        int up = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                up++;
            }

            ans += up;
        }

        return ans;
    }
};