class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto &x : nums) mp[x]++;
        if ((int)mp.size() == n) return false;
        return true;
    }
};