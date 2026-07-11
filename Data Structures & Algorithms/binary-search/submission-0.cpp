class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] == target) return mid;
            else if (a[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
