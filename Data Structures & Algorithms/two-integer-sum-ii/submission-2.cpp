class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans = {-1, -1};
        for (int i = 0; i < n - 1; i++) {

            int lo = i + 1, hi = n - 1;
            while (lo <= hi) {

                int mid = (lo + hi) >> 1;
                int sum = numbers[i] + numbers[mid];
                if (sum == target) {
                    ans = {i+1, mid+1};
                    break;
                }
                else if (sum < target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return ans;
    }
};
