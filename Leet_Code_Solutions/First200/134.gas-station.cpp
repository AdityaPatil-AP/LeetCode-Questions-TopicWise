class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // Brute Force.
        // I'll will try starting from every index, and return if I am successful at
        // any one.

        // Greedy Way.
        // Curr_gas indicates the total_gas we have right now.
        int curr_gas = 0, total_gas = 0, total_cost = 0;
        int starting_point = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];
            curr_gas += (gas[i] - cost[i]);
            if (curr_gas < 0)
            {
                // Reseting our curr_fuel
                curr_gas = 0;
                // Now our new starting point would be the next point, because all the stations before it had no sufficient fuel
                // to go to the next station, so our new starting_point would be i + 1.
                starting_point = i + 1;
            }
        }
        return (total_gas < total_cost) ? -1 : starting_point;
    }
};