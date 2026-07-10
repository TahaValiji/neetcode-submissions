class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int maxi = 0;
        int mini = p[0];
        for (int i = 1; i < n; i++) {
            mini = min(mini, p[i]);
            maxi = max(maxi, p[i] - mini);
        }

        return maxi;
    }
};
