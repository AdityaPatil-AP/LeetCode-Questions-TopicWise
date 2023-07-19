class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        //     // Number of People
        int n = people.size();
        //     // Number of required skills.
        int m = req_skills.size();

        //     // Now the value of req_skills is very small which alludes us to track
        //     // the number of skills covered so far using bitmask.

        //     // Instead of working with strings for the skills. We will work with
        //     // the Indices. We use a Hashmap. to keep the index of each skill.
        unordered_map<string, int> mp;
        int i = 0;
        for (auto skill : req_skills)
        {
            mp[skill] = i++;
        }

        //     // Now as each skill has a number we can represent every set of skills
        //     // with a bitmask. An integer in range of 0 - [(2^m) - 1].

        //     // The Problem is to find the smallest team such that the union of the skill
        //     // sets of its members is the set of all required skills -> {0, 1, 2, ---, m - 1};
        //     // Reformulation -> We need to find the smallest team such that the bitwise OR
        //     // of the bitmasks representing the skill sets of it's members is [(2^m) - 1].

        //     // I will have to store the people I choose for the current task.
        //     // If they make up the whole set of the required tasks, we can say this as
        //     // an answer.

        //     // State.
        //     // dp[skillsMask] -> represents the smallest team number to possess all the
        //     // skills from skillsMask.

        vector<int> skillsMaskOfPerson(n);

        for (int i = 0; i < n; i++)
        {
            for (string skill : people[i])
            {
                skillsMaskOfPerson[i] |= (1 << mp[skill]);
            }
        }

        //    vector<long long> dp(1 << m, (1ll << n) - 1);

        //    dp[0] = 0;

        //    for(int skillsMask = 1;skillsMask < (1 << m);skillsMask++){
        //        for(int i = 0;i < n;i++){
        //            int smallerSkillsMask = (skillsMask & ~skillsMaskOfPerson[i]);
        //            if(smallerSkillsMask != skillsMask){
        //                long long peopleMask = dp[smallerSkillsMask] | (1ll << i);
        //                if(__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask])){
        //                    dp[skillsMask] = peopleMask;
        //                }
        //            }
        //        }
        //    }

        //    long long answerMask = dp[(1 << m) - 1];
        //    vector<int> ans;
        //    for(int i = 0;i < n;i++){
        //        if((answerMask >> i) & 1){
        //            ans.push_back(i);
        //        }
        //    }

        //    return ans;

        // Top Down for Practice.
        // Just create a good state and check if the transitions are following it
        // well or not. If yes go on with the answer.

        vector<long long> dp(1 << m, -1);

        function<long long(int)> f = [&](int skillsMask) -> long long
        {
            if (skillsMask == 0)
            {
                return 0;
            }
            if (dp[skillsMask] != -1)
            {
                return dp[skillsMask];
            }

            for (int i = 0; i < n; i++)
            {
                int smallerSkillsMask = (skillsMask & ~skillsMaskOfPerson[i]);
                if (smallerSkillsMask != skillsMask)
                {
                    long long peopleMask = f(smallerSkillsMask) | (1ll << i);
                    if (dp[skillsMask] == -1 || __builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask]))
                    {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }

            return dp[skillsMask];
        };

        long long answerMask = f((1 << m) - 1);

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if ((answerMask >> i) & 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};