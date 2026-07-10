class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int max_water = 0;

        while (l < r) {
            int mini = min(h[l], h[r]);
            max_water = max(max_water, mini * (r - l));
            if (h[l] == mini) l++;
            else r--;
        }

        return max_water;
    }
};
