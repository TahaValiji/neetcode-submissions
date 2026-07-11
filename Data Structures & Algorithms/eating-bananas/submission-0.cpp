class Solution {
public:
    bool chk(int k, vector<int>& p, int h) {
        int cnt = 0;
        for (auto &x : p) cnt += ceil((double)x / (double)k);
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        int lo = 1, hi = *(max_element(p.begin(), p.end()));
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (chk(mid, p, h)) hi = mid - 1;
            else lo = mid + 1;
        }

        return lo;
    }
};
