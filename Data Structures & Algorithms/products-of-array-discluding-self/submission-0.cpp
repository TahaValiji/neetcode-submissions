class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();

        vector<int> pre(n), suf(n);

        pre[0] = a[0];
        suf[n-1] = a[n-1];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] * a[i];
        }
        for (int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1] * a[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) ans[i] = suf[i+1];
            else if (i == n-1) ans[i] = pre[i-1];
            else ans[i] = pre[i-1]*suf[i+1];
        }

        return ans;
    }
};
