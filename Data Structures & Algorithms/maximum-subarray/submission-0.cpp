class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();

        int curr = a[0];
        int maxi = curr;
        for (int i = 1; i < n; i++) {
            curr = max(a[i], curr + a[i]);
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};
