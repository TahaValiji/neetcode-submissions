class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        set<pair<int, int>, greater<pair<int, int>>> st;
        for (auto &p : mp) {
            st.insert({p.second, p.first});
        }

        vector<int> ans;
        for (auto &it : st) {
            ans.push_back(it.second);
            if ((int)ans.size() == k) break;
        }
        return ans;
    }
};
