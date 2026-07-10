class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int w = 0;
        vector<int> pre(n), suf(n);
        pre[0] = h[0];
        suf[n - 1] = h[n - 1];
        for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], h[i]);
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], h[i]);
        for (int i = 0; i < n; i++)  w += min(pre[i], suf[i]) - h[i];
        return w;
    }
};
