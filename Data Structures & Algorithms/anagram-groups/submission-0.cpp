class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        set<string> st;
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            st.insert(s);
        }

        int cnt = 0;
        for (auto s : st) mp[s] = cnt++;
        vector<vector<string>> res(cnt);
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            res[mp[s]].push_back(strs[i]);
        }
        return res;
    }
};
