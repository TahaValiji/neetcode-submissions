class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int cnt = 0;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            cnt += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if (cnt < 0) {
                cnt = 0;
                idx = i+1;
            }
        }

        return (total < 0) ? -1 : idx;
    }
};
