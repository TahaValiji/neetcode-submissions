class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int maxi = 0;
        int mini = p[0];
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, p[i] - mini);
            mini = min(mini, p[i]);
        }

        return maxi;
    }
};
